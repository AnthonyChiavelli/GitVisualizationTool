#ifndef REPOSITORY_H
#define REPOSITORY_H
#include commitnode.h

class Repository {

public:
    Repository(CommitNode &initialCommit);

    CommitNode getInitialCommit() const;
    void setInitialCommit(const CommitNode &value);

private:
    CommitNode initialCommit;
};

#endif // REPOSITORY_H
