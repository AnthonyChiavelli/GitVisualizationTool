#include "gcommitarrow.h"

GCommitArrow::GCommitArrow(QGraphicsItem *parent) : QGraphicsItem(parent) {

}

GCommitArrow::GCommitArrow(GCommitNode *origin, GCommitNode *destination) {
    this->source = origin;
    this->destination = destination;
}


QRectF GCommitArrow::boundingRect() const {


    return QRectF(source->pos(), QSizeF(destination->pos().x() - source->pos().x(),
                                      destination->pos().y() - source->pos().y()))
        .normalized();
}

void GCommitArrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {


    // The line of the arrow
   QLineF arrowLine(source->pos(), destination->pos());
   painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

   painter->drawLine(arrowLine);

}

