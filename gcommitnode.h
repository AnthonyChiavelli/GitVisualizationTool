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
    // Get the location the commit arrow should point to
    int getNextArrowStartPoint();

protected:

    // Mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:

    // Size of node
    int size;

    // Relatives
    vector<GCommitNode *> parentGNodes;
    vector<GCommitNode *> childrenGNodes;

signals:

public slots:

};

#endif // GCOMMITNODE_H
