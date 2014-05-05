#ifndef GCOMMITARROW_H
#define GCOMMITARROW_H

#include <QGraphicsItem>
#include "gcommitnode.h"

class GCommitArrow : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    explicit GCommitArrow(QGraphicsItem *parent = 0);
    // Performs actual object rendering
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    // Source and destination nodes
    GCommitNode *source;
    GCommitNode *destination;

signals:

public slots:

};

#endif // GCOMMITARROW_H
