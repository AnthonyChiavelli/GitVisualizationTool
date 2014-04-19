#include "commitnode.h"

CommitNode::CommitNode() {
}

vector<CommitNode *> CommitNode::getParents() const
{
    return parents;
}

void CommitNode::setParents(const vector<CommitNode *> &value)
{
    parents = value;
}
vector<CommitNode *> CommitNode::getChildren() const
{
    return children;
}

void CommitNode::setChildren(const vector<CommitNode *> &value)
{
    children = value;
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







