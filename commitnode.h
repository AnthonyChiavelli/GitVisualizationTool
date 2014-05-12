#ifndef COMMITNODE_H
#define COMMITNODE_H

#include <QDateTime>
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

    QString getMessage() const;
    void setMessage(QString &value);

    QDateTime getCommitTime() const;
    void setCommitTime(QDateTime &commitTime);
    void setCommitTime(qint64 &commitTimeInMillis);

private:
    QSet<CommitNode *>* parents = new QSet<CommitNode *>();
    QSet<CommitNode *>* children = new QSet<CommitNode *>();
    GitUser committer;
    GitUser author;
    QString message;
    QDateTime commitTime;
};

#endif // COMMITNODE_H
