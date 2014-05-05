#include "branch.h"

Branch::Branch() {
    // Empty constructor
}

Branch::Branch(string &name, Sha1 &commitSHA, int &type) :
        name(name), commitSha(commitSHA), type(type) {
}

string Branch::getName() const
{
    return name;
}
void Branch::setName(const string &value)
{
    name = value;
}

int Branch::getType() const
{
    return type;
}
void Branch::setType(int value)
{
    type = value;
}
Sha1 Branch::getCommitSha() const
{
    return commitSha;
}

void Branch::setCommitSha(const Sha1 &value)
{
    commitSha = value;
}




