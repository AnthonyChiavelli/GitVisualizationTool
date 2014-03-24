#include "ggraphicsscene.h"
#include "gcommitnode.h"
#include <vector>

GGraphicsScene::GGraphicsScene(QObject *parent) : QGraphicsScene(parent) {

    // Set up our coordinate rectange
    this->setSceneRect(0, 0, SCENE_X, SCENE_Y);
}

GCommitNode *GGraphicsScene::convertCommitNodeToGCommitNode(CommitNode const & commitNode, GCommitNode const * parent, int nodeDepth) {

    // Check if this gcommit node has already been instantiated
    //TODO use getSha() once implemented
    GCommitNode *gCommitNode;
    if(this->allGCommitNodes.find(commitNode.getAuthor().getEmail()) != allGCommitNodes.end()) {
        gCommitNode = this->allGCommitNodes.at(commitNode.getAuthor().getEmail());
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
    gCommitNode->sha = commitNode.getAuthor().getEmail();
    gCommitNode->depth = nodeDepth;

    // If there are any children, recursively call this on them
    vector<CommitNode> children = commitNode.getChildren();
    if (children.size() > 0) {
        // Increase the node depth for these children
        nodeDepth++;
        // Recursively call ourselves for each child and add result to our set of children
        for (vector<CommitNode>::iterator it = children.begin(); it !=children.end(); ++it ) {
            gCommitNode->childrenGNodes.push_back(convertCommitNodeToGCommitNode(*it, gCommitNode, nodeDepth));
        }
    }

    // Add this commit to a list of all commits
    this->allGCommitNodes.insert({gCommitNode->sha, gCommitNode});
    return gCommitNode;
}

void GGraphicsScene::renderScene(GCommitNode *rootNode) {

    vector<GCommitNode *> nodes;

    // Enqueue the root node
    nodes.push_back(rootNode);

    // While we have nodes remaining
    while (!nodes.empty()) {

        // For each node on the queue
        for (vector<GCommitNode *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
            // Render, pop, and add its children to queue
            GCommitNode * currentNode = nodes.back();
            this->addItem(currentNode);
            nodes.pop_back();
            for (vector<GCommitNode *>::iterator it = currentNode->childrenGNodes.begin(); it != currentNode->childrenGNodes.end(); ++it) {
                nodes.push_back(*it);
            }
        }
    }
}
