#ifndef LOCALREPOPARSER_H
#define LOCALREPOPARSER_H

#include <string>
#include <QHash>
#include <QString>
#include "commitnode.h"
#include "branch.h"

namespace LocalRepoParser {

    // Returns a full snapshot of the commit history for the given local repo
    CommitNode* getGitTree(string const &pathToGitFolder);

    // Returns the local branch with the given name
    Branch* getBranch(string const &pathToGitFolder, string const &branchName);

    // Returns all local branches
    QList<Branch *> getBranches (string const &pathToGitFolder);

}

#endif // LOCALREPOPARSER_H
