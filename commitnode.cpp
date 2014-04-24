#include "commitnode.h"

CommitNode::CommitNode() {
}

QSet<CommitNode *>* CommitNode::getParents() const
{
    return parents;
}

void CommitNode::addParent(CommitNode *parent) {
    parents->insert(parent);
}

QSet<CommitNode *>* CommitNode::getChildren() const
{
    return children;
}

void CommitNode::addChild(CommitNode *child) {
    children->insert(child);
}

GitUser CommitNode::getCommitter() const
{
    return committer;
}

void CommitNode::setCommitter(const GitUser &value)
{
    committer = value;
}
GitUser CommitNode::getAuthor() const
{
    return author;
}

void CommitNode::setAuthor(const GitUser &value)
{
    author = value;
}
string CommitNode::getMessage() const
{
    return message;
}

void CommitNode::setMessage(const string &value)
{
    message = value;
}
string CommitNode::getDateAndTime() const
{
    return dateAndTime;
}

void CommitNode::setDateAndTime(const string &value)
{
    dateAndTime = value;
}

CommitNode::~CommitNode() {
    delete parents;
    delete children;
}







