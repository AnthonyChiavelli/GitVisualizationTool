#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include "sha1.h"

#define LOCAL_BRANCH 0
#define REMOTE_BRANCH 1

using namespace std;

class Branch {

public:
    Branch();
    Branch(string &name, Sha1 &commitSha, int &type);

    string getName() const;
    void setName(const string &value);

    int getType() const;
    void setType(int value);

    Sha1 getCommitSha() const;
    void setCommitSha(const Sha1 &value);

private:
    string name;
    Sha1 commitSha;
    int type;
};

#endif // BRANCH_H
