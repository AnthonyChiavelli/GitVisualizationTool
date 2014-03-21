#include "gcommitnode.h"
#include <QGraphicsView>

GCommitNode::GCommitNode(QGraphicsItem *parent) : QGraphicsItem(parent) {

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QRectF GCommitNode::boundingRect() const {
    return QRectF(0,0,100,100);
}


void GCommitNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {

    // Render the rectangle
    painter->setBrush(Qt::cyan);
    painter->drawRect(0, 0, 100, 100);
    painter->setBrush(Qt::darkCyan);
    painter->setPen(Qt::darkCyan);
    painter->drawText(0, 0, "Commit: ^%&$654");

}

int GCommitNode::getNextArrowStartPoint() {
    return 0;
}

bool operator==(GCommitNode &lhs, GCommitNode &rhs) {
    return lhs.sha == rhs.sha;
}
