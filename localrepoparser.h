#ifndef LOCALREPOPARSER_H
#define LOCALREPOPARSER_H

#include <string>
#include <QHash>
#include <QString>

using namespace std;

class CommitNode;
class Branch;

#include "commitnode.h"
#include "branch.h"
#include "ggraphicsscene.h"

namespace LocalRepoParser {

    // Returns a full snapshot of the commit history for the given local repo
    CommitNode* getGitTree(string const &pathToGitFolder, GGraphicsScene &canvas);

    Branch* getBranch(string const &pathToGitFolder, string const &branchName);

    // Returns all local branches
    QList<Branch *> getBranches (string const &pathToGitFolder);

    class Emitter {
        signals:
            static void localRepoChanged();
    };

}

#endif // LOCALREPOPARSER_H
