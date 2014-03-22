#include "gcommitnode.h"
#include <QGraphicsView>

#include "commitsha.h"

GCommitNode::GCommitNode(QGraphicsItem *parent) : QGraphicsItem(parent) {

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QRectF GCommitNode::boundingRect() const {
    return QRectF(0,0,nodeWidth,nodeHeight);
}


void GCommitNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {

    // Render the rectangle
    painter->setBrush(Qt::cyan);
    painter->drawRect(0, 0, nodeWidth, nodeHeight);

    // Calculate the width of the text boxes
    QFont font;
    QFontMetrics fontMetrics(font);
    int labelTextWidth = fontMetrics.width("Commit: ");
    int shaTextWidth = fontMetrics.width("123456789");

    // Calculate margin necessary to center text boxes in node
    int labelTextMargin = (nodeWidth - labelTextWidth) / 2;
    int shaTextMargin = (nodeWidth - shaTextWidth) / 2;

    // Render the text boxes
    painter->setBrush(Qt::darkCyan);
    painter->setPen(Qt::darkCyan);
    CommitSha cs("2cd35f475899c74a90dba4345f11f0362268a952");
    painter->drawText(labelTextMargin, 25, "Commit:");
    painter->drawText(shaTextMargin, 40, cs.getStringOfLength(6).c_str());

}

int GCommitNode::getNextArrowStartPoint() {
    return 0;
}

bool operator==(GCommitNode &lhs, GCommitNode &rhs) {
    return lhs.sha == rhs.sha;
}
