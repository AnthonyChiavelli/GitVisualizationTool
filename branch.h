#ifndef BRANCH_H
#define BRANCH_H
#include <string>
#include "commitnode.h"

class Branch
{
public:
    Branch(string &name, CommitNode &commit, int &type);

    string getName() const;
    void setName(const string &value);

    CommitNode getCommit() const;
    void setCommit(const CommitNode &value);

    int getType() const;
    void setType(int value);

private:
    string name;
    CommitNode commit;
    int type;
};

#endif // BRANCH_H
