#include "gcommitnode.h"
#include <QGraphicsView>

GCommitNode::GCommitNode(QGraphicsItem *parent) : QGraphicsItem(parent), size(100) {

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QRectF GCommitNode::boundingRect() const {
    return QRectF(0,0,size,size);
}

void GCommitNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {

    // Render the rectangle
    painter->setBrush(Qt::cyan);
    painter->drawRect(0, 0, size, size);
    painter->setBrush(Qt::darkCyan);
    painter->setPen(Qt::darkCyan);
    painter->drawText(0, 0, "Commit: ^%&$654");

}

int GCommitNode::getNextArrowStartPoint() {
    return 0;
}


void GCommitNode::mousePressEvent(QGraphicsSceneMouseEvent *event){

}

void GCommitNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

}
