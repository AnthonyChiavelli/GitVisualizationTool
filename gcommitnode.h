#ifndef GCOMMITNODE_H
#define GCOMMITNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <vector>

using namespace std;

/**Graphics properties**/

#define NODE_WIDTH 100
#define NODE_HEIGHT NODE_WIDTH
#define ROW_HEIGHT 120
#define COLUMN_WIDTH 120


/*
 * Graphical node representing a commit
 */
class GCommitNode : public QObject, public QGraphicsItem {
    Q_OBJECT
        Q_INTERFACES(QGraphicsItem)

public:

    // -- Constructors --
    // Create a node as a child of a parent
    GCommitNode(QGraphicsItem *parent = 0);


    // -- Graphics method (required) --
    // Returns estimate of size
    QRectF boundingRect() const;
    // Performs actual object rendering
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // -- Relatives --
    vector<const GCommitNode *> parentGNodes;
    vector<GCommitNode *> childrenGNodes;

    // -- Commit Data --
    string author;
    string message;
    string sha;

    // -- Tree Situation --
    // How far away from root node we are
    int depth;
    // Number of cousins we have
    int numberOfCousins;

    // -- Operators --
    // Implement equality comparison between gcommit nodes
    friend bool operator==(GCommitNode & lhs, GCommitNode & rhs);


private:

    // Helper methods to help render the node
    void renderNodeRectangle(QPainter *painter);
    void renderNodeText(QPainter *painter);

protected:

    // Mouse events
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:

public slots:

};

#endif // GCOMMITNODE_H
