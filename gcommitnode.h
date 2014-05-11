#ifndef GCOMMITNODE_H
#define GCOMMITNODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <vector>
#include "gituser.h"
#include "sha1.h"

using namespace std;

// -- Appearance properties --

#define NODE_WIDTH 70
#define NODE_HEIGHT 50
#define NODE_CORNER_RADIUS 1.5

#define NODE_LABEL_TEXT "commit"
#define NODE_LABEL_Y 20
#define NODE_SHA_Y 35

#define NODE_TEXT_COLOR QColor(255,255,255)
#define NODE_BG_COLOR QColor(99,102,133)

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

    vector<GCommitNode *> *getParentGNodes();

    vector<GCommitNode *> *getChildrenGNodes();

    // Children of ours for which we are the youngest parent
    vector<GCommitNode *> *getCloseChildren();

    int getNumberOfLeaves();
    void setNumberOfLeaves(int value);

    int getDepth();
    void setDepth(int value);

    int getNumberOfCousins();
    void setNumberOfCousins(int value);

    int getXEnd();
    void setXEnd(int value);

    int getXStart();
    void setXStart(int value);

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
    // Our allocated space - the space we can use for ourselves and all of our children
    int allocatedWidth;
    // The X-range of our allocated space
    int xStart, xEnd;
    // Number of leaves we have
    int numberOfLeaves;
    // How far away from root node we are
    int depth;
    // Number of cousins we have
    int numberOfCousins;

private:

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
