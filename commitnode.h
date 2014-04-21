#ifndef COMMITNODE_H
#define COMMITNODE_H
#include <QSet>

#include "gitobject.h"
#include "gituser.h"

using namespace std;

class CommitNode : public GitObject {

public:
    CommitNode();
    ~CommitNode();

    QSet<CommitNode *>* getParents() const;
    void addParent(CommitNode *parent);

    QSet<CommitNode *>* getChildren() const;
    void addChild(CommitNode *child);

    GitUser getCommitter() const;
    void setCommitter(const GitUser &value);

    GitUser getAuthor() const;
    void setAuthor(const GitUser &value);

    string getMessage() const;
    void setMessage(const string &value);

    string getDateAndTime() const;
    void setDateAndTime(const string &value);

private:
    QSet<CommitNode *>* parents = new QSet<CommitNode *>();
    QSet<CommitNode *>* children = new QSet<CommitNode *>();
    GitUser committer;
    GitUser author;
    string message;
    string dateAndTime;
};

#endif // COMMITNODE_H
