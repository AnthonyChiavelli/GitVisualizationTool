#ifndef COMMITNODE_H
#define COMMITNODE_H
#include <vector>

#include "gitobject.h"
#include "gituser.h"

using namespace std;

class CommitNode : public GitObject {

public:
    CommitNode();
    CommitNode(Sha1 &sha);
    ~CommitNode();

    vector<CommitNode *>* getParents() const;
    void addParent(const CommitNode * parent);

    vector<CommitNode *>* getChildren() const;
    void addChild();

    GitUser getCommitter() const;
    void setCommitter(const GitUser &value);

    GitUser getAuthor() const;
    void setAuthor(const GitUser &value);

    string getMessage() const;
    void setMessage(const string &value);

    string getDateAndTime() const;
    void setDateAndTime(const string &value);

private:
    Sha1 sha;
    vector<CommitNode *>* parents = new vector<CommitNode *>();
    vector<CommitNode *>* children = new vector<CommitNode *>();
    GitUser committer;
    GitUser author;
    string message;
    string dateAndTime;
};

#endif // COMMITNODE_H
