#include "gcommitarrow.h"
#include <math.h>


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

    // Figure out position of source node relative to destination node
    QPointF sourcePoint;
    QPointF destinationPoint;
    QRectF sourceRect = source->sceneBoundingRect();
    QRectF destinationRect = destination->sceneBoundingRect();
    // If child node is completely below parent node
    if(sourceRect.bottom() < destinationRect.top()) {
        // Originate the arrow from the middle top, terminate in middle bottom of child
        sourcePoint = QPointF(sourceRect.left() + (sourceRect.width() / 2), sourceRect.bottom());
        destinationPoint = QPointF(destinationRect.left() + (destinationRect.width() / 2), destinationRect.top());
    }
    else if (destinationRect.bottom() < sourceRect.top()) {
        // Originate the arrow from the middle top, terminate in middle bottom of child
        sourcePoint = QPointF(sourceRect.left() + (sourceRect.width() / 2), sourceRect.top());
        destinationPoint = QPointF(destinationRect.left() + (destinationRect.width() / 2), destinationRect.bottom());
    }
    else if (sourceRect.right() < destinationRect.left()) {
        // Originate the arrow from the middle right, terminate in middle left of child
        sourcePoint = QPointF(sourceRect.right(), sourceRect.top() +(sourceRect.height() / 2));
        destinationPoint = QPointF(destinationRect.left(), destinationRect.top() + (destinationRect.height() / 2));
    }
    else if (sourceRect.left() > destinationRect.right()) {
        // Originate the arrow from the middle lef, terminate in middle right of child
        sourcePoint = QPointF(sourceRect.left(), sourceRect.top() +(sourceRect.height() / 2));
        destinationPoint = QPointF(destinationRect.right(), destinationRect.top() + (destinationRect.height() / 2));
    }


    // Set up pen
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(Qt::black);

    // The line of the arrow
    QLineF arrowLine(sourcePoint, destinationPoint);

    // Render line of arrow
    painter->drawLine(arrowLine);

    // The head of the arrow
    // Calculate angle of line as arccos of hypotenuse over adjacent
    double angleOfLine = acos(arrowLine.dx() / arrowLine.length());

    // Keep our angle between 0 and 180
    if (arrowLine.dy() >= 0) {
        angleOfLine = (PI * 2) - angleOfLine;
    }

    // Calculate the two points of the triangle (the other being the endpoint of the line) that forms the arrow head
    QPointF arrowHeadPoint1 = sourcePoint + QPointF(sin(angleOfLine + PI / 3) * 10, cos(angleOfLine + PI / 3) * 15);
    QPointF arrowHeadPoint2 = sourcePoint + QPointF(sin(angleOfLine + PI - PI / 3) * 10, cos(angleOfLine + PI - PI / 3) * 15);

    // Render arrow head
    painter->drawPolygon(QPolygonF() << arrowLine.p1() << arrowHeadPoint1 << arrowHeadPoint2);

}

