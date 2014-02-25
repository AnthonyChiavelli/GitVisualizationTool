#ifndef GCOMMITNODE_H
#define GCOMMITNODE_H

#include <QGraphicsItem>
#include <QPainter>

/*
 * Graphical node representing a commit
 */
class GCommitNode : public QObject, public QGraphicsItem {
    Q_OBJECT

public:

    GCommitNode(QGraphicsItem *parent);
    // QGraphicsItems must override these two methods
    // Returns estimate of size
    QRectF boundingRect() const;
    // Performs actual object rendering
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    // Size of node
    int size;

signals:

public slots:

};

#endif // GCOMMITNODE_H
