#ifndef GCOMMITARROW_H
#define GCOMMITARROW_H
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include "gcommitnode.h"

#define PI 3.14159265

// -- Graphics properties --
#define ARROW_HEAD_WIDTH 8
#define ARROW_HEAD_LENGTH 14



class GCommitArrow : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    GCommitArrow(GCommitNode *origin, GCommitNode *destination);
    explicit GCommitArrow(QGraphicsItem *parent = 0);

    // -- Graphics method (required) --
    // Returns estimate of size
    QRectF boundingRect() const;
    // Performs actual object rendering
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // -- Source and destination nodes --
    GCommitNode *source;
    GCommitNode *destination;

signals:

public slots:

};

#endif // GCOMMITARROW_H
