#ifndef GGRAPHICSSCENE_H
#define GGRAPHICSSCENE_H
#include <map>
#include "gcommitnode.h"
#include "commitnode.h"
#include <QGraphicsScene>

/**Graphics properties**/
#define SCENE_X 500
#define SCENE_Y 500

class GGraphicsScene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit GGraphicsScene(QObject *parent = 0);

    // Converts a CommitNode, produced by the parser, to a GCommitNode to be drawn on the canvas
    GCommitNode *convertCommitNodeToGCommitNode(CommitNode const & commitNode, GCommitNode const * parent = 0, int nodeDepth = 0);

    // A global set of all nodes mapped by sha
    map<string, GCommitNode *> allGCommitNodes;

signals:

public slots:

};

#endif // GGRAPHICSSCENE_H
