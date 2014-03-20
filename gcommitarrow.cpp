#include "gcommitarrow.h"

GCommitArrow::GCommitArrow(QGraphicsItem *parent) : QGraphicsItem(parent) {


}

void GCommitArrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {

    // Get starting point
    int x = this->destination->getNextArrowStartPoint();

    // Determine color
    painter->setBrush(Qt::blue);

    // Draw our line
    painter->drawLine(x, x, x+100, x+100);

}
