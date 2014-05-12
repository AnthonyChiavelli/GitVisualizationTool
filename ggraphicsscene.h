#ifndef GGRAPHICSSCENE_H
#define GGRAPHICSSCENE_H
#include <QGraphicsScene>

#include <map>

#include "commitnode.h"
#include "gcommitarrow.h"
#include "gcommitnode.h"

// -- Appearance Properties --
#define CANVAS_SPACE_PER_NODE 150
#define CANVAS_ROW_HEIGHT 90
#define CANVAS_ROW_OFFSET 50

#define CANVAS_WIDTH 700
#define CANVAS_HEIGHT 700

#define CANVAS_BG_COLOR QColor(232,232,232)

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

    // The arrows that connect the nodes
    vector<GCommitArrow *> arrows;

private:
    // Render a node and its children in the space space from startX to endX
    void renderNode(GCommitNode *node, int startX, int endX);

signals:

public slots:

};

#endif // GGRAPHICSSCENE_H
