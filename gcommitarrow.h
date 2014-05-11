#ifndef GCOMMITARROW_H
#define GCOMMITARROW_H

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include "gcommitnode.h"

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

private:


    // Arrow Head
    QPolygonF arrowHead;

signals:

public slots:

};

#endif // GCOMMITARROW_H
