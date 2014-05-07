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
QString CommitNode::getMessage() const
{
    return message;
}

void CommitNode::setMessage(QString &value)
{
    message = value;
}
QDateTime CommitNode::getCommitTime() const
{
    return commitTime;
}

void CommitNode::setCommitTime(QDateTime &value)
{
    commitTime = value;
}

void CommitNode::setCommitTime(qint64 &commitTimeInMillis) {
    commitTime = QDateTime::fromMSecsSinceEpoch(commitTimeInMillis);
}

CommitNode::~CommitNode() {
    delete parents;
    delete children;
}







