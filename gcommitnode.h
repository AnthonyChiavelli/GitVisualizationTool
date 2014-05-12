#ifndef GCOMMITNODE_H
#define GCOMMITNODE_H

#include <QGraphicsItem>
#include <QDateTime>
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

    GCommitNode(QGraphicsItem *parent = 0);

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

    QDateTime getDateAndTime() ;
    void setDateAndTime(const QDateTime &value);

    Sha1 getSha();
    void setSha(const Sha1 &value);

    vector<GCommitNode *> *getParentGNodes();

    vector<GCommitNode *> *getChildrenGNodes();

    // Children of ours for which we are the youngest parent
    vector<GCommitNode *> *getCloseChildren();

    // Relatives
    vector<const GCommitNode *> parentGNodes;
    vector<GCommitNode *> childrenGNodes;

    // Commit data
    string author;
    string message;
    QDateTime dateAndTime;

    // -- Relatives --
    vector<GCommitNode *> parentGNodes;
    vector<GCommitNode *> childrenGNodes;


    // How far away from root node we are
    int depth;
    // Number of cousins we have
    int numberOfCousins;

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
