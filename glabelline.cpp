#include "glabelline.h"
#include <math.h>

using namespace std;

GLabelLine::GLabelLine() {

}

GLabelLine::GLabelLine(QGraphicsItem *source, QGraphicsItem *destination) : source(source), destination(destination){
}

QRectF GLabelLine::boundingRect() const {

    return QRectF(source->pos(), QSizeF(destination->pos().x() - source->pos().x(), destination->pos().y() - source->pos().y())).normalized();
}

void GLabelLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {

    // Figure out position of source node relative to destination node
    QPointF sourcePoint;
    QPointF destinationPoint;
    QRectF sourceRect = source->sceneBoundingRect();
    QRectF destinationRect = destination->sceneBoundingRect();
    // If child is completely below parent
    if(sourceRect.bottom() < destinationRect.top()) {
        // Originate the line from the middle top, terminate in middle bottom of child
        qreal sourceBottomPoint = min(max(destinationRect.left() + (destinationRect.width() / 2), sourceRect.left()), sourceRect.right());
        sourcePoint = QPointF(sourceRect.left() + (sourceRect.width() / 2), sourceRect.bottom());
        sourcePoint = QPointF(sourceBottomPoint, sourceRect.bottom());
        destinationPoint = QPointF(destinationRect.left() + (destinationRect.width() / 2), destinationRect.top());
    }
    // If child is completely above parent
    else if (destinationRect.bottom() < sourceRect.top()) {
        qreal sourceTopPoint = min(max(destinationRect.left() + (destinationRect.width() / 2), sourceRect.left()), sourceRect.right());
        sourcePoint = QPointF(sourceTopPoint, sourceRect.top());
        destinationPoint = QPointF(destinationRect.left() + (destinationRect.width() / 2), destinationRect.bottom());
    }
    // If the child is completely to the right of parent
    else if (sourceRect.right() < destinationRect.left()) {
        qreal sourceRightPoint = min(max(destinationRect.top() + (destinationRect.height() / 2), sourceRect.top()), sourceRect.bottom());
        sourcePoint = QPointF(sourceRect.right(), sourceRightPoint);
        destinationPoint = QPointF(destinationRect.left(), destinationRect.top() + (destinationRect.height() / 2));
    }
    // If the child is completely to the left of parent
    else if (sourceRect.left() > destinationRect.right()) {
        qreal sourceLeftPoint = min(max(destinationRect.top() + (destinationRect.height() / 2), sourceRect.top()), sourceRect.bottom());
        sourcePoint = QPointF(sourceRect.left(), sourceLeftPoint);
        destinationPoint = QPointF(destinationRect.right(), destinationRect.top() + (destinationRect.height() / 2));
    }


    // Set up pen
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(Qt::black);

    // Render line
    QLineF arrowLine(sourcePoint, destinationPoint);
    painter->drawLine(arrowLine);

}
