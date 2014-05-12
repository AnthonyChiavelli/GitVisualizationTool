#include "gcommitnode.h"
#include "QColor"

#include <QGraphicsView>

#include "sha1.h"
#include "gcommitarrow.h"

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

    // Get a pointer to our containing scene
    QGraphicsScene *thisScene = scene();
    // If this method is called before scene is set up, we'll get NULL
    if (thisScene != 0) {
        // Refresh everything in the scene
        thisScene->update();
    }

    // Pass along event
    return QGraphicsItem::itemChange(change, value);
}


bool operator==(GCommitNode &lhs, GCommitNode &rhs) {
    return lhs.sha.getFullString() == rhs.sha.getFullString();
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

vector< GCommitNode *> *GCommitNode::getParentGNodes()  { return &parentGNodes; }

vector<GCommitNode *> *GCommitNode::getChildrenGNodes()  { return &childrenGNodes; }

vector<GCommitNode *> *GCommitNode::getCloseChildren() {
    int counter = 0;
    vector<GCommitNode *> *closeChildren = new vector<GCommitNode*>();
    for (vector<GCommitNode *>::iterator child = this->childrenGNodes.begin(); child != this->childrenGNodes.end(); child++) {
        GCommitNode *childNode = *child;
        bool haveYoungerParents = false;
        //Check if they have younger parents
        for (vector<GCommitNode *>::iterator childParent = childNode->getParentGNodes()->begin(); childParent != childNode->getParentGNodes()->end(); childParent++) {
            GCommitNode *childParentNode = *childParent;
            if (childParentNode->depth > this->depth) {
                haveYoungerParents = true;
            }
        }
        if (!haveYoungerParents) {
            closeChildren->push_back(childNode);
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




