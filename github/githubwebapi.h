#ifndef GITHUBWEBAPI_H
#define GITHUBWEBAPI_H
#include <QString>
#include <vector>
#include <utility>
#include "branch.h"
#include "commitnode.h"
#include "gituser.h"


namespace GitHubWebApi {
    struct hubBranch {
        QString sha;
        QString name;
    };
    GitUser* validUser(char *usr, char *pass);
    QHash<pair<string, string>, QString>* parseBranches(string usr, string repo);
  //  pair<string, string> parseBranch(string const &url);
    void parseCommitNode(string sha, string usr, string repo, CommitNode *commit);
};

#endif // GITHUBWEBAPI_H
