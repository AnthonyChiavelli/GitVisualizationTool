#ifndef GCOMMITNODE_H
#define GCOMMITNODE_H
#include <QDateTime>
#include <QGraphicsItem>
#include <QPainter>

#include <vector>
#include <set>

#include "gituser.h"
#include "gbranchlabel.h"
#include "sha1.h"

using namespace std;

// Forward declaration to avoid circular dependencies
class GCommitArrow;

// -- Appearance properties --

#define NODE_WIDTH 70
#define NODE_HEIGHT 50
#define NODE_CORNER_RADIUS 1.5

#define NODE_LABEL_TEXT "commit"
#define NODE_LABEL_Y 20
#define NODE_SHA_Y 35

#define NODE_TEXT_COLOR QColor(255,255,255)
#define NODE_BG_COLOR QColor(99,102,133)
#define NODE_BG_COLOR_SELECTED QColor(229,150,47)

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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

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

    QDateTime getDateAndTime() ;
    void setDateAndTime(const QDateTime &value);

    Sha1 getSha();
    void setSha(const Sha1 &value);

    set<GCommitNode *> *getParentGNodes();

    set<GCommitNode *> *getChildrenGNodes();

    // Children of ours for which we are the youngest parent
    set<GCommitNode *> *getCloseChildren();

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

    vector<GCommitArrow *> *getTouchingArrows();

    // Add a branch and return count of branches (including that one)
    int addBranchLabel(GBranchLabel *branchLabel);

    int getChildRanking() const;
    void setChildRanking(int value);

private:

    // -- Attributes of the commit --
    GitUser committer;
    GitUser author;
    Sha1 sha;
    string message;
    QDateTime dateAndTime;

    // -- Relatives --
    set<GCommitNode *> parentGNodes;
    set<GCommitNode *> childrenGNodes;


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
    // Branches that point to us
    vector<GBranchLabel *> ourbranches;
    // Helps decide the best place to stick the branch label
    int childRanking;

    // -- Helper methods to help render the node --
    void renderNodeRectangle(QPainter *painter);
    void renderNodeText(QPainter *painter);

protected:

    // -- QT Callbacks --
    // Called when there is some change done to an item
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

signals:

public slots:

};

#endif // GCOMMITNODE_H
