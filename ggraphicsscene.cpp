#include "ggraphicsscene.h"
#include "gcommitnode.h"
#include <vector>
#include <QSet>

GGraphicsScene::GGraphicsScene(QObject *parent) : QGraphicsScene(parent) {

    // Set up our coordinate rectange
    this->setSceneRect(0, 0, SCENE_X, SCENE_Y);

    // Build up test tree
    GCommitNode *root = new GCommitNode();
    this->renderNode(root);

}

GCommitNode *GGraphicsScene::convertCommitNodeToGCommitNode(CommitNode* commitNode, GCommitNode* parent, int nodeDepth) {


    // Check if this gcommit node has already been instantiated
    GCommitNode *gCommitNode;
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
        gCommitNode->getParentGNodes().push_back(parent);
    }

    // Set attributes for this g node
    gCommitNode->setSha(commitNode->getSha1());
    gCommitNode->setCommitter(commitNode->getCommitter());
    gCommitNode->setAuthor(commitNode->getAuthor());
    gCommitNode->setDateAndTime(commitNode->getDateAndTime());
    gCommitNode->setMessage(commitNode->getMessage());

    gCommitNode->setDepth(nodeDepth);

    // If there are any children, recursively call this on them
    QSet<CommitNode *>* children = commitNode->getChildren();
    if (children->size() > 0) {
        // Increase the node depth for these children
        nodeDepth++;
        // Recursively call ourselves for each child and add result to our set of children
        for (QSet<CommitNode *>::iterator it = children->begin(); it !=children->end(); ++it ) {
            gCommitNode->getChildrenGNodes().push_back(convertCommitNodeToGCommitNode(*it, gCommitNode, nodeDepth));
        }
    }

    // Add this commit to a list of all commits, if it hasn't already been
    if (!recylcingOldNode) {
        this->allGCommitNodes.insert({commitNode->getSha1().getFullString(), gCommitNode});
    }
    return gCommitNode;
}

void GGraphicsScene::renderNode(GCommitNode *node) {




    vector<GCommitNode *> nodes;
    int currentLevel = 0;

    // Enqueue the root node
    nodes.push_back(node);

    // While we have nodes remaining
    while (!nodes.empty()) {

        // For each node on the queue
        vector<GCommitNode *> currentLevelVector(nodes);
        int cousinCounter = 0;
        for (vector<GCommitNode *>::iterator it = currentLevelVector.begin(); it != currentLevelVector.end() && !currentLevelVector.empty(); ++it, ++cousinCounter) {
            // Render, pop, and add its children to queue
            GCommitNode * currentNode = *it;
            int nodeDepth = currentNode->getDepth();
            currentNode->setPos((500 / (currentLevelVector.size() + 1)) * (cousinCounter+1), (currentNode->getDepth() + 1) * 150);
            this->addItem(currentNode);
            //currentLevelVector.pop_back();
            nodes.pop_back();
            for (vector<GCommitNode *>::iterator it2 = currentNode->getChildrenGNodes().begin(); it2 != currentNode->getChildrenGNodes().end(); ++it2) {
                nodes.push_back(*it2);
            }
        }
        currentLevel++;
    }
}
