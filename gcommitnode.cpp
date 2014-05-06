#include "gcommitnode.h"
#include <QGraphicsView>

#include "sha1.h"

GCommitNode::GCommitNode(QGraphicsItem *parent) : QGraphicsItem(parent) {

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    // Establish our position in the scene based on our place in the tree
    //this->setPos(500 / (1 + 1), ROW_HEIGHT * depth);

}


QRectF GCommitNode::boundingRect() const {
    return QRectF(0,0,NODE_WIDTH,NODE_HEIGHT);
}



void GCommitNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {

    // Render the rectangle
    renderNodeRectangle(painter);

    // Render the node text
    renderNodeText(painter);

}


void GCommitNode::renderNodeRectangle(QPainter *painter) {

    painter->setBrush(Qt::cyan);
    painter->drawRect(0, 0, NODE_WIDTH, NODE_HEIGHT);
}

void GCommitNode::renderNodeText(QPainter *painter) {

    QFont font;
    QFontMetrics fontMetrics(font);
    int labelTextWidth = fontMetrics.width("Commit: ");
    int shaTextWidth = fontMetrics.width(this->sha.getStringOfLength(6).c_str());

    // Calculate margin necessary to center text boxes in node
    int labelTextMargin = (NODE_WIDTH - labelTextWidth) / 2;
    int shaTextMargin = (NODE_WIDTH - shaTextWidth) / 2;

    // Render the text boxes
    painter->setBrush(Qt::darkCyan);
    painter->setPen(Qt::darkCyan);
    Sha1 cs("2cd35f475899c74a90dba4345f11f0362268a952");
    painter->drawText(labelTextMargin, 25, "Commit:");
    painter->drawText(shaTextMargin, 40, this->sha.getStringOfLength(6).c_str());
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

string GCommitNode::getDateAndTime()  { return dateAndTime; }
void GCommitNode::setDateAndTime(const string &value) { dateAndTime = value; }

Sha1 GCommitNode::getSha()  { return sha; }
void GCommitNode::setSha(const Sha1 &value) { sha = value; }

vector< GCommitNode *> *GCommitNode::getParentGNodes()  { return &parentGNodes; }

vector<GCommitNode *> *GCommitNode::getChildrenGNodes()  { return &childrenGNodes; }

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



