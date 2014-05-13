#ifndef GLABELLINE_H
#define GLABELLINE_H

#include <QGraphicsItem>

class QPainter;

class GLabelLine : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    GLabelLine();
    GLabelLine(QGraphicsItem *source, QGraphicsItem *destination);

    // -- Graphics method (required) --
    // Returns estimate of size
    QRectF boundingRect() const;
    // Performs actual object rendering
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // -- Source and destination nodes --
    QGraphicsItem *source;
    QGraphicsItem *destination;
};

#endif // GLABELLINE_H
