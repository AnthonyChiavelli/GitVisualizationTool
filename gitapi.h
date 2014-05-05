#ifndef GITAPI_H
#define GITAPI_H

#include "gitapiresponse.h"
#include "branch.h"
#include "sha1.h"

namespace GitApi{
    GitAPIResponse gitInit(std::string& repoPath);
    GitAPIResponse gitCommit(std::string& repoPath, std::string& message);
    GitAPIResponse gitCheckout(std::string& repoPath, Branch targetBranch);
    //GitAPIResponse gitAdd(std::string& repoPath, std::vector<std::string> files);
    GitAPIResponse gitAdd_All(std::string& repoPath);
    GitAPIResponse gitBranch(std::string& repoPath, std::string newBranchName);
    GitAPIResponse gitMerge(std::string& repoPath, Branch targetBranch, std::string& message);
    //GitAPIResponse gitMergeMultipleBranches(std::string& repoPath, std::vector<Branch> targetBranchs, std::string& message);
    GitAPIResponse gitStatus(std::string& repoPath);
    GitAPIResponse showGitObjectContents(std::string& repoPath, Sha1 hash);

}

#endif // GITAPI_H
