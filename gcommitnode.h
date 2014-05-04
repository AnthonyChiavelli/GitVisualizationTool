#ifndef GCOMMITNODE_H
#define GCOMMITNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <vector>
#include "gituser.h"
#include "sha1.h"

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

    // -- Operators --
    // Implement equality comparison between gcommit nodes
    friend bool operator==(GCommitNode & lhs, GCommitNode & rhs);


    // -- Getters and setters --
    GitUser getCommitter();
    void setCommitter(const GitUser &value);

    GitUser getAuthor();
    void setAuthor(const GitUser &value);

    string getMessage();
    void setMessage(const string &value);

    string getDateAndTime() ;
    void setDateAndTime(const string &value);

    Sha1 getSha();
    void setSha(const Sha1 &value);

    vector<GCommitNode *> getParentGNodes();

    vector<GCommitNode *> getChildrenGNodes();

    int getNumberOfLeaves();
    void setNumberOfLeaves(int value);

    int getDepth();
    void setDepth(int value);

    int getNumberOfCousins();
    void setNumberOfCousins(int value);

private:

    // -- Attributes of the commit --
    GitUser committer;
    GitUser author;
    Sha1 sha;
    string message;
    string dateAndTime;

    // -- Relatives --
    vector<GCommitNode *> parentGNodes;
    vector<GCommitNode *> childrenGNodes;

    // -- Tree Situation --
    // Number of leaves we have
    int numberOfLeaves;
    // How far away from root node we are
    int depth;
    // Number of cousins we have
    int numberOfCousins;

    // -- Helper methods to help render the node --
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
