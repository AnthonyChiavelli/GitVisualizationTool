#ifndef GITHUBREPOPARSER_H
#define GITHUBREPOPARSER_H
#include "githubwebapi.h"
#include <map>
#include <string>
#include "commitnode.h"
#include "branch.h"

namespace GithubRepoParser {

    // Returns a full snapshot of the commit history for the given github repo
    CommitNode* getGitTree(string const &url);

    // Return a branch from a github repo
    Branch* getBranch(string const &url, string const &branchName);

}

#endif // GITHUBREPOPARSER_H
