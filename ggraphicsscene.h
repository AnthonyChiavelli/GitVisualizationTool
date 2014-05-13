#ifndef GGRAPHICSSCENE_H
#define GGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <string>
#include <vector>
#include <map>

class Branch;
class GCommitArrow;
class GCommitNode;
class CommitNode;

using namespace std;

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
    map<string, GCommitNode *> *allGCommitNodes;

    // The arrows that connect the nodes
    vector<GCommitArrow *> *arrows;

    // Render the branch labels in this repo
    void renderBranchLabels(QList<Branch *> branches);

    string getCurrentRepoPath() const;
    void setCurrentRepoPath(const string &value);

protected:


private:
    // Render a node and its children in the space space from startX to endX
    void renderNode(GCommitNode *node, int startX, int endX);

    // Initiate rendering
    void renderRepository(string repoPath);

    // Current repo path
    string currentRepoPath;

signals:

public slots:
    // Re-render canvas, something has changed
    void notifyRepoChange();

};

#endif // GGRAPHICSSCENE_H
