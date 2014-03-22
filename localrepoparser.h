#ifndef LOCALREPOPARSER_H
#define LOCALREPOPARSER_H

#include <string>
#include "commitnode.h"
#include "branch.h"

namespace LocalRepoParser {

    // Returns a full snapshot of the commit history for the given local repo
    CommitNode& getGitTree(string &pathToGitFolder);

    // Returns the full history for the given commit (identified by it's SHA-1)
    CommitNode& getCommitHistory(CommitNode &commit);

    Branch& getBranch(string &pathToGitFolder, string &branchName);

}

#endif // LOCALREPOPARSER_H
