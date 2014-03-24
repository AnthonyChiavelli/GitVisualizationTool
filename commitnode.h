#ifndef COMMITNODE_H
#define COMMITNODE_H
#include <vector>

#include "gituser.h"

using namespace std;

class CommitNode {

public:
    CommitNode();

    vector<CommitNode> getParents() const;
    void setParents(const vector<CommitNode> &value);

    vector<CommitNode> getChildren() const;
    void setChildren(const vector<CommitNode> &value);

    GitUser getCommitter() const;
    void setCommitter(const GitUser &value);

    GitUser getAuthor() const;
    void setAuthor(const GitUser &value);

    string getMessage() const;
    void setMessage(const string &value);

    string getDateAndTime() const;
    void setDateAndTime(const string &value);

private:
    vector<CommitNode> parents;
    vector<CommitNode> children;
    GitUser committer;
    GitUser author;
    string message;
    string dateAndTime;
};

#endif // COMMITNODE_H
