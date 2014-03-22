#ifndef BRANCH_H
#define BRANCH_H

#include <string>

#define LOCAL_BRANCH 0
#define REMOTE_BRANCH 1

using namespace std;

class Branch {

public:
    Branch();
    Branch(string &name, string &commitSHA, int &type);

    string getName() const;
    void setName(const string &value);

    int getType() const;
    void setType(int value);

    string getCommitSHA() const;
    void setCommitSHA(const string &value);

private:
    string name;
    string commitSHA;
    int type;
};

#endif // BRANCH_H
