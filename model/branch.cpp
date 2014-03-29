#include "branch.h"

Branch::Branch(string &name, CommitNode &commit, int &type)
{
    this->name = name;
    this->commit = commit;
    this->type = type;
}

string Branch::getName() const
{
    return name;
}

void Branch::setName(const string &value)
{
    name = value;
}
CommitNode Branch::getCommit() const
{
    return commit;
}

void Branch::setCommit(const CommitNode &value)
{
    commit = value;
}
int Branch::getType() const
{
    return type;
}

void Branch::setType(int value)
{
    type = value;
}



