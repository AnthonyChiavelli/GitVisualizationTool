#ifndef LOCALREPOSITORY_H
#define LOCALREPOSITORY_H
#include "repository.h"
#include "remote.h"

using namespace std;

class LocalRepository : public Repository {

  public:
    LocalRepository(string &absolutePath, vector<Remote> remotes);

    string getAbsolutePath() const;
    void setAbsolutePath(const string &value);

    vector<Remote> getRemotes() const;
    void setRemotes(const vector<Remote> &value);

private:
    string absolutePath;
    vector<Remote> remotes;
};

#endif // LOCALREPOSITORY_H
