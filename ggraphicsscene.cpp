#include "ggraphicsscene.h"
#include "gcommitnode.h"
#include <vector>
#include <QSet>

GGraphicsScene::GGraphicsScene(QObject *parent) : QGraphicsScene(parent) {

    //this->renderScene(root);

}

GCommitNode *GGraphicsScene::convertCommitNodeToGCommitNode(CommitNode const * commitNode, GCommitNode const * parent, int nodeDepth) {

    GCommitNode *gCommitNode;

    // Check if this gcommit node has already been instantiated
    bool recylcingOldNode = false;

    if(this->allGCommitNodes.find(commitNode->getSha1().getFullString()) != allGCommitNodes.end()) {
        gCommitNode = this->allGCommitNodes.at(commitNode->getSha1().getFullString());
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
    gCommitNode->sha = commitNode->getSha1().getFullString();
    //TODO change from string to sha1
    gCommitNode->depth = nodeDepth;

    // If there are any children, recursively call this on them
    QSet<CommitNode *>* children = commitNode->getChildren();
    if (children->size() > 0) {
        // Increase the node depth for these children
        nodeDepth++;
        // Recursively call ourselves for each child and add result to our set of children
        for (QSet<CommitNode *>::iterator it = children->begin(); it !=children->end(); ++it ) {
            gCommitNode->childrenGNodes.push_back(convertCommitNodeToGCommitNode(*it, gCommitNode, nodeDepth));
        }
    }

    // Add this commit to a list of all commits, if it hasn't already been
    if (!recylcingOldNode) {
        this->allGCommitNodes.insert({commitNode->getSha1().getFullString(), gCommitNode});
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
        vector<GCommitNode *> currentLevelVector(nodes);
        int cousinCounter = 0;
        for (vector<GCommitNode *>::iterator it = currentLevelVector.begin(); it != currentLevelVector.end() && !currentLevelVector.empty(); ++it, ++cousinCounter) {
            // Render, pop, and add its children to queue
            GCommitNode * currentNode = *it;
            currentNode->setPos((500 / (currentLevelVector.size() + 1)) * (cousinCounter+1), (currentNode->depth + 1) * 150);
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
