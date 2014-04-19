#include "ggraphicsscene.h"
#include "gcommitnode.h"
#include <vector>

GGraphicsScene::GGraphicsScene(QObject *parent) : QGraphicsScene(parent) {

    // Set up our coordinate rectange
    this->setSceneRect(0, 0, SCENE_X, SCENE_Y);

    // Build up test tree
    GCommitNode *root = new GCommitNode(0, 0);
    GCommitNode *uncle = new GCommitNode(1, 1);
    uncle->parentGNodes.push_back(root);
    GCommitNode *aunt = new GCommitNode(1, 1);
    aunt->parentGNodes.push_back(root);
    root->childrenGNodes.push_back(aunt);
    root->childrenGNodes.push_back(uncle);

    GCommitNode *cousin = new GCommitNode(2, 0);
    cousin->parentGNodes.push_back(aunt);
    aunt->childrenGNodes.push_back(cousin);

    this->renderScene(root);

}

GCommitNode *GGraphicsScene::convertCommitNodeToGCommitNode(CommitNode const * commitNode, GCommitNode const * parent, int nodeDepth) {


    // Check if this gcommit node has already been instantiated
    //TODO use getSha() once implemented
    GCommitNode *gCommitNode;
    bool recylcingOldNode = false;
    if(this->allGCommitNodes.find(commitNode->getAuthor().getEmail()) != allGCommitNodes.end()) {
        gCommitNode = this->allGCommitNodes.at(commitNode->getAuthor().getEmail());
        recylcingOldNode = true;
    }
    // Otherwise make a new one
    else {
        gCommitNode = new GCommitNode();
    }

    // If this is a recursive call, we'll have a parent to attach
    if (parent != 0) {
        gCommitNode->parentGNodes.push_back(parent);
    }

    // Set attributes for this g node
    gCommitNode->sha = commitNode->getAuthor().getEmail();
    gCommitNode->depth = nodeDepth;

    // If there are any children, recursively call this on them
    vector<CommitNode *> children = commitNode->getChildren();
    if (children.size() > 0) {
        // Increase the node depth for these children
        nodeDepth++;
        // Recursively call ourselves for each child and add result to our set of children
        for (vector<CommitNode *>::iterator it = children.begin(); it !=children.end(); ++it ) {
            gCommitNode->childrenGNodes.push_back(convertCommitNodeToGCommitNode(*it, gCommitNode, nodeDepth));
        }
    }

    // Add this commit to a list of all commits, if it hasn't already been
    if (!recylcingOldNode) {
        this->allGCommitNodes.insert({gCommitNode->sha, gCommitNode});
    }
    return gCommitNode;
}

void GGraphicsScene::renderScene(GCommitNode *rootNode) {

    vector<GCommitNode *> nodes;
    int currentLevel = 0;

    // Enqueue the root node
    nodes.push_back(rootNode);

    // While we have nodes remaining
    while (!nodes.empty()) {

        // For each node on the queue
        int cousinCount = 0;
        vector<GCommitNode *> currentLevelVector(nodes);
        for (vector<GCommitNode *>::iterator it = currentLevelVector.begin(); it != currentLevelVector.end() && !currentLevelVector.empty(); ++it, ++cousinCount) {
            // Render, pop, and add its children to queue
            GCommitNode * currentNode = *it;
            currentNode->setPos(500 / currentLevelVector.size(), currentLevel * 150);
            this->addItem(currentNode);
            //currentLevelVector.pop_back();
            nodes.pop_back();
            for (vector<GCommitNode *>::iterator it2 = currentNode->childrenGNodes.begin(); it2 != currentNode->childrenGNodes.end(); ++it2) {
                nodes.push_back(*it2);
            }
        }
        currentLevel++;
    }
}
