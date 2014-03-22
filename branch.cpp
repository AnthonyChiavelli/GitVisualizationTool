#include "branch.h"

Branch::Branch() {
    // Empty constructor
}

Branch::Branch(string &name, string &commitSHA, int &type) :
        name(name), commitSHA(commitSHA), type(type) {
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
string Branch::getCommitSHA() const
{
    return commitSHA;
}

void Branch::setCommitSHA(const string &value)
{
    commitSHA = value;
}




