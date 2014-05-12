#ifndef GGRAPHICSSCENE_H
#define GGRAPHICSSCENE_H

#include <QGraphicsScene>
#include "gcommitnode.h"

class GRepoScene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit GRepoScene(QObject *parent = 0);

    // Attach a commit node as the root commit node
    void attachRootCommitNode(GCommitNode *);

    // Draw the scene
    void renderScene();

private:
    // Root commit node
    GCommitNode *rootGCommitNode;


};

#endif // GGRAPHICSSCENE_H
