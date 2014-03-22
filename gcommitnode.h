#ifndef GCOMMITNODE_H
#define GCOMMITNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <vector>

using namespace std;

// Graphics properties
#define nodeWidth 100
#define nodeHeight nodeWidth

/*
 * Graphical node representing a commit
 */
class GCommitNode : public QObject, public QGraphicsItem {
    Q_OBJECT

public:

    GCommitNode(QGraphicsItem *parent = 0);
    // QGraphicsItems must override these two methods
    // Returns estimate of size
    QRectF boundingRect() const;
    // Performs actual object rendering
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // Get the location the commit arrow should point to
    int getNextArrowStartPoint();

    // Size of node
    int size;

    // Relatives
    vector<const GCommitNode *> parentGNodes;
    vector<GCommitNode *> childrenGNodes;

    // Commit data
    string author;
    string message;
    string sha;

    // How far away from root node we are
    int depth;

    // Implement equality comparison between gcommit nodes
    friend bool operator==(GCommitNode & lhs, GCommitNode & rhs);

protected:
    // Mouse events
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);



signals:

public slots:

};

#endif // GCOMMITNODE_H
