#include <vector>
#include <algorithm>
#include <QSet>
#include "QColor"
#include "ggraphicsscene.h"
#include "gcommitnode.h"
#include "gcommitarrow.h"
#include "gbranchlabel.h"
#include "localrepoparser.h"
#include "logger.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <iostream>

GGraphicsScene::GGraphicsScene(QObject *parent) : QGraphicsScene(parent) {

    // Build up test tree
    GCommitNode *root = convertCommitNodeToGCommitNode(LocalRepoParser::getGitTree("/home/anthony/dev/homework/GitVisualizationTool/test_repo"));

    // Measure tree
    int totalLeaves = this->measurePhase(root);

    // Size canvas coordinate grid based on measurement
    this->setSceneRect(0, 0, totalLeaves * CANVAS_SPACE_PER_NODE, 1000); //TODO fix number
    this->setBackgroundBrush(QBrush(CANVAS_BG_COLOR, Qt::SolidPattern));

    // Render tree
    this->renderPhase(root);

    //TODO: remove. add test branch label
    GBranchLabel *testLabel1 = new GBranchLabel(QString("hello"));
    testLabel1->setPos(QPoint(100,100));
    this->addItem(testLabel1);


}

GCommitNode *GGraphicsScene::convertCommitNodeToGCommitNode(CommitNode* commitNode, GCommitNode* parent, int nodeDepth) {

    // Check if this gcommit node has already been instantiated
    GCommitNode *gCommitNode;
    bool reusingExistingNode = false;
    if(this->allGCommitNodes.find(commitNode->getSha1().getFullString()) != allGCommitNodes.end()) {
        gCommitNode = this->allGCommitNodes.at(commitNode->getSha1().getFullString());
        reusingExistingNode = true;

    }
    // Otherwise make a new one
    else {
        gCommitNode = new GCommitNode();

        // Set attributes for this g node
        gCommitNode->setSha(commitNode->getSha1());
        gCommitNode->setCommitter(commitNode->getCommitter());
        gCommitNode->setAuthor(commitNode->getAuthor());
        gCommitNode->setDateAndTime(commitNode->getCommitTime());
        gCommitNode->setMessage(commitNode->getMessage().toStdString());
    }

    // If this is a recursive call, we'll have a parent to attach
    if (parent != 0) {
        gCommitNode->getParentGNodes()->push_back(parent);
    }

    // Node depth should be maximum of all depths calculated for this node (which differ
    // based on which parent we came from
    if (reusingExistingNode) {
        gCommitNode->setDepth(max(nodeDepth, gCommitNode->getDepth()));
    }
    // New node, no max needed
    else {
        gCommitNode->setDepth(nodeDepth);
    }

    // If there are any children, recursively call this on them
    QSet<CommitNode *>* children = commitNode->getChildren();
    if (children->size() > 0) {
        // Increase the node depth for these children
        nodeDepth++;
        // Recursively call ourselves for each child and add result to our set of children
        for (QSet<CommitNode *>::iterator it = children->begin(); it !=children->end(); ++it ) {
            GCommitNode * newNode = convertCommitNodeToGCommitNode(*it, gCommitNode, nodeDepth);
            gCommitNode->getChildrenGNodes()->push_back(newNode);
            // Add an arrow from this to the child to the global set of arrows
            GCommitArrow * newArrow = new GCommitArrow(gCommitNode, newNode);
            this->arrows.push_back(newArrow);
        }
    }

    // Add this commit to a list of all commits, if it hasn't already been
    if (!reusingExistingNode) {
        this->allGCommitNodes.insert({commitNode->getSha1().getFullString(), gCommitNode});
    }
    return gCommitNode;
}



void GGraphicsScene::renderPhase(GCommitNode *node) {

    // Figure out allocated width for whole tree
    int totalAllocatedWidth = node->getNumberOfLeaves() * CANVAS_SPACE_PER_NODE;

    // Render tree starting at root node
    this->renderNode(node, 0, totalAllocatedWidth);

    // Render arrows
    for (vector<GCommitArrow *>::iterator arrow = this->arrows.begin(); arrow != this->arrows.end(); arrow++) {
        this->addItem(*arrow);
    }

}

void GGraphicsScene::renderNode(GCommitNode *node, int startX, int endX) {

    // Position yourself in the middle of your allocated width
    int xPos = startX + ((endX - startX) / 2.0);
    node->setPos(xPos, CANVAS_ROW_OFFSET + CANVAS_ROW_HEIGHT * node->getDepth());

    // Render
    this->addItem(node);

    // If we're a leaf, we're done
    if (node->getChildrenGNodes()->empty()) {
        return;
    }


    // Divide up your allocated space into even slots for each child (later to be adjusted based on
    // subtree leaf number)
    int spacePerChild = (int)((double)(endX - startX) / (double)node->getCloseChildren()->size());

    // Iterate over children, allocate them space inside us, and render them
    int childNumber = 0;
    vector<GCommitNode *> *children = node->getCloseChildren();
    for (vector<GCommitNode *>::iterator it = children->begin(); it !=children->end(); ++it ) {
        this->renderNode(*it, startX + (spacePerChild * childNumber), startX + ((spacePerChild * (childNumber + 1))));
        childNumber++;
    }


}

int GGraphicsScene::measurePhase(GCommitNode *node) {

    vector<GCommitNode *> *children = node->getCloseChildren();

    // Recurse down tree if we are an inner node
    if (children->size() > 0) {
        int leavesOnSubTrees = 0;
        for (vector<GCommitNode *>::iterator it = children->begin(); it !=children->end(); ++it ) {
            leavesOnSubTrees += measurePhase(*it);
        }
        // Number of leaves to a node is the leaves on all of its subtrees added together
        node->setNumberOfLeaves(leavesOnSubTrees);
        return leavesOnSubTrees;
    }
    // Otherwise we are a leaf
    else {
        // We have no leaves
        node->setNumberOfLeaves(0);
        // Our parent gets +1 leaves
        return 1;
    }


}

