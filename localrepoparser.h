#ifndef LOCALREPOPARSER_H
#define LOCALREPOPARSER_H

#include <string>
#include <QHash>
#include <QString>

using namespace std;

class CommitNode;
class Branch;

namespace LocalRepoParser {

    // Returns a full snapshot of the commit history for the given local repo
    CommitNode* getGitTree(string const &pathToGitFolder);

    Branch* getBranch(string const &pathToGitFolder, string const &branchName);

    // Returns all local branches
    QList<Branch *> getBranches (string const &pathToGitFolder);

}

#endif // LOCALREPOPARSER_H
