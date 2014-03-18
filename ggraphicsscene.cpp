#include "ggraphicsscene.h"

GGraphicsScene::GGraphicsScene(QObject *parent) : QGraphicsScene(parent) {

public:

    // Attach a commit node as the root commit node
    void attachRootCommitNode(int rootNode);

    // Draw the scene
    void renderScene();
}
