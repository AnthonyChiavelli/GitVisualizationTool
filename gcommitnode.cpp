#include <QColor>
#include <QCoreApplication>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

#include "gcommitarrow.h"
#include "ggraphicsscene.h"
#include "gcommitnode.h"
#include "gitbranchdialog.h"
#include "sha1.h"
#include "logger.h"
#include "mainwindow.h"

GCommitNode::GCommitNode(QGraphicsItem *parent) : QGraphicsItem(parent) {

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QRectF GCommitNode::boundingRect() const {
    return QRectF(0,0,NODE_WIDTH, NODE_HEIGHT);
}

void GCommitNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {

    // Enable anti-aliasing so that rounded corners are rendered correctly
    painter->setRenderHint(QPainter::Antialiasing);

    // Render the rectangle
    renderNodeRectangle(painter);

    // Render the node text
    renderNodeText(painter);
}

void GCommitNode::renderNodeRectangle(QPainter *painter) {

    painter->setBrush(NODE_BG_COLOR);
    QRect rect = QRect(0, 0, NODE_WIDTH, NODE_HEIGHT);
    painter->drawRoundedRect(rect, NODE_CORNER_RADIUS, NODE_CORNER_RADIUS);
}

void GCommitNode::renderNodeText(QPainter *painter) {

    // Set up font
    QFont font;
    font.setPointSize(10);

    // "Commit" and sha label metrics
    QFontMetrics fontMetrics(font);
    int labelTextWidth = fontMetrics.width(NODE_LABEL_TEXT);
    int shaTextWidth = fontMetrics.width(this->sha.getStringOfLength(6).c_str());

    // Calculate margin necessary to center text labels in node
    int labelTextMargin = (NODE_WIDTH - labelTextWidth) / 2;
    int shaTextMargin = (NODE_WIDTH - shaTextWidth) / 2;

    // Render the text boxes
    painter->setBrush(NODE_TEXT_COLOR);
    painter->setPen(NODE_TEXT_COLOR);
    painter->setFont(font);
    QPointF labelTextPosition = QPointF(labelTextMargin, NODE_LABEL_Y);
    painter->drawText(labelTextPosition, NODE_LABEL_TEXT);
    QPointF shaTextPosition = QPointF(shaTextMargin, NODE_SHA_Y);
    painter->drawText(shaTextPosition, this->sha.getStringOfLength(6).c_str());
}


QVariant GCommitNode::itemChange(GraphicsItemChange change, const QVariant &value) {

    // If this was a position change
    if (change == ItemPositionChange) {
        // Get a pointer to our containing scene
        QGraphicsScene *thisScene = scene();
        // If this method is called before scene is set up, we'll get NULL
        if (thisScene != 0) {
            // Refresh everything in the scene
            thisScene->update();
        }

        // Calculate our delta
        QPointF newPos = value.toPointF();
        QPointF oldPos = this->pos();
        int deltaX = newPos.x() - oldPos.x();
        int deltaY = newPos.y() - oldPos.y();

        // Move branch pointers in the same motion
        for (vector<GBranchLabel *>::iterator it = this->ourbranches.begin(); it != this->ourbranches.end(); it++) {
            GBranchLabel *branchLabel = *it;
            branchLabel->setPos(branchLabel->pos().x() + deltaX, branchLabel->pos().y() + deltaY);
        }
    }

    // Pass along event
    return QGraphicsItem::itemChange(change, value);
}

void GCommitNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // Continue to propagate it
    QGraphicsItem::mousePressEvent(event);

    // On right click, make a new branch
    if (event->button() == Qt::RightButton) {
        // Launch new branch dialog
        GitBranchDialog *newBranchDialog = new GitBranchDialog();
        newBranchDialog->setModal(true);
        newBranchDialog->exec();

        if (scene() != 0) {
            // Refresh everything in the scene
            (GGraphicsScene(scene())).refreshRepo();
        }
    }
    // On left click, show information in side bar
    if (event->button() == Qt::LeftButton) {
//        MainWindow *window = (MainWindow *) QCoreApplication::instance();
        MainWindow *window = qobject_cast<MainWindow *>(qApp->activeWindow());

        window->updateInfoWindow(this);
    }

}


bool operator==(GCommitNode &lhs, GCommitNode &rhs) {
    return lhs.sha.getFullString() == rhs.sha.getFullString();
}

int GCommitNode::addBranchLabel(GBranchLabel *branchLabel) {
    this->ourbranches.push_back(branchLabel);
    return this->ourbranches.size();
}


// -- Getters and setters --
GitUser GCommitNode::getCommitter() {return committer;}
void GCommitNode::setCommitter(const GitUser &value) {committer = value;}

GitUser GCommitNode::getAuthor()  { return author;}
void GCommitNode::setAuthor(const GitUser &value) { author = value; }

string GCommitNode::getMessage()  { return message; }
void GCommitNode::setMessage(const string &value) { message = value; }

QDateTime GCommitNode::getDateAndTime()  { return dateAndTime; }
void GCommitNode::setDateAndTime(const QDateTime &value) { dateAndTime = value; }

Sha1 GCommitNode::getSha()  { return sha; }
void GCommitNode::setSha(const Sha1 &value) { sha = value; }

set< GCommitNode *> *GCommitNode::getParentGNodes()  { return &parentGNodes; }

set<GCommitNode *> *GCommitNode::getChildrenGNodes()  { return &childrenGNodes; }

set<GCommitNode *> *GCommitNode::getCloseChildren() {
    int counter = 0;
    set<GCommitNode *> *closeChildren = new set<GCommitNode*>();
    for (set<GCommitNode *>::iterator child = this->childrenGNodes.begin(); child != this->childrenGNodes.end(); child++) {
        GCommitNode *childNode = *child;
        bool haveYoungerParents = false;
        //Check if they have younger parents
        for (set<GCommitNode *>::iterator childParent = childNode->getParentGNodes()->begin(); childParent != childNode->getParentGNodes()->end(); childParent++) {
            GCommitNode *childParentNode = *childParent;
            if (childParentNode->depth > this->depth) {
                haveYoungerParents = true;
            }
        }
        if (!haveYoungerParents) {
            closeChildren->insert(childNode);
        }
    }
    return closeChildren;
}

int GCommitNode::getNumberOfLeaves()  { return numberOfLeaves; }
void GCommitNode::setNumberOfLeaves(int value) { numberOfLeaves = value; }

int GCommitNode::getDepth()  { return depth; }
void GCommitNode::setDepth(int value) { depth = value; }

int GCommitNode::getNumberOfCousins()  { return numberOfCousins; }
void GCommitNode::setNumberOfCousins(int value) { numberOfCousins = value; }

int GCommitNode::getXEnd() { return xEnd; }
void GCommitNode::setXEnd(int value) { xEnd = value; }
int GCommitNode::getXStart() { return xStart; }
void GCommitNode::setXStart(int value) { xStart = value; }

int GCommitNode::getChildRanking() const { return childRanking; }
void GCommitNode::setChildRanking(int value) { childRanking = value; }
