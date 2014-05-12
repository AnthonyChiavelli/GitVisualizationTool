#include "greposcene.h"

GRepoScene::GRepoScene(QObject *parent) : QGraphicsScene(parent) {


}

void GRepoScene::attachRootCommitNode(GCommitNode *gNode) {
    this->rootGCommitNode = gNode;
}

void GRepoScene::renderScene() {
    this->addItem(this->rootGCommitNode);
}
