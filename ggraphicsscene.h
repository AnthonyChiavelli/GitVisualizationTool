#ifndef GGRAPHICSSCENE_H
#define GGRAPHICSSCENE_H
#include <map>
#include "gcommitnode.h"
#include "commitnode.h"
#include <QGraphicsScene>

/**Graphics properties**/
#define X_SPACE_PER_LEAF 200
#define Y_SPACE_PER_LEVEL 150
#define SCENE_X 700
#define SCENE_Y 700

class GGraphicsScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit GGraphicsScene(QObject *parent = 0);

    // Converts a CommitNode, produced by the parser, to a GCommitNode to be drawn on the canvas
    GCommitNode *convertCommitNodeToGCommitNode(CommitNode* commitNode, GCommitNode* parent = 0, int nodeDepth = 0);

    // Traverse the tree and assign an allocated space to each node
    int measurePhase(GCommitNode *node);

    // Traverse the tree and render each node
    void renderPhase(GCommitNode *node);

    // A global set of all nodes mapped by sha
    map<string, GCommitNode *> allGCommitNodes;

private:
    // Render a node and its children in the space space from startX to endX
    void renderNode(GCommitNode *node, int startX, int endX);

signals:

public slots:

};

#endif // GGRAPHICSSCENE_H
