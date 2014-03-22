#include "gcommitnode.h"
#include <QGraphicsView>

#include "commitsha.h"

GCommitNode::GCommitNode(QGraphicsItem *parent) : QGraphicsItem(parent) {

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    // Establish our position in the scene based on our place in the tree
    this->setPos(COLUMN_WIDTH / (1 + 1), ROW_HEIGHT * 1);
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

int GCommitNode::getNextArrowStartPoint() {
    return 0;
}

void GCommitNode::renderNodeRectangle(QPainter *painter) {

    painter->setBrush(Qt::cyan);
    painter->drawRect(0, 0, NODE_WIDTH, NODE_HEIGHT);
}

void GCommitNode::renderNodeText(QPainter *painter) {

    QFont font;
    QFontMetrics fontMetrics(font);
    int labelTextWidth = fontMetrics.width("Commit: ");
    int shaTextWidth = fontMetrics.width("123456789");

    // Calculate margin necessary to center text boxes in node
    int labelTextMargin = (NODE_WIDTH - labelTextWidth) / 2;
    int shaTextMargin = (NODE_WIDTH - shaTextWidth) / 2;

    // Render the text boxes
    painter->setBrush(Qt::darkCyan);
    painter->setPen(Qt::darkCyan);
    CommitSha cs("2cd35f475899c74a90dba4345f11f0362268a952");
    painter->drawText(labelTextMargin, 25, "Commit:");
    painter->drawText(shaTextMargin, 40, cs.getStringOfLength(6).c_str());
}

bool operator==(GCommitNode &lhs, GCommitNode &rhs) {
    return lhs.sha == rhs.sha;
}
