#ifndef GITAPI_H
#define GITAPI_H

#include "gitapiresponse.h"
#include "branch.h"
#include "remote.h"
#include "sha1.h"
#include <vector>
#include <QStringList>

namespace GitApi{
    GitAPIResponse gitInit(std::string& repoPath);
    GitAPIResponse gitCommit(std::string& repoPath, std::string& message);
    GitAPIResponse gitCheckout(std::string& repoPath, Branch targetBranch);
    GitAPIResponse gitAdd(std::string& repoPath, QStringList& files);
    //GitAPIResponse gitAdd(string& repoPath, vector<string> files);
    GitAPIResponse gitAdd_All(std::string& repoPath);
    GitAPIResponse gitBranch(std::string& repoPath, std::string newBranchName);
    //QStringList gitBranches(std::string& repoPath);
    GitAPIResponse gitMerge(std::string& repoPath, Branch& targetBranch, std::string& message);
    GitAPIResponse gitMergeByName(std::string& repoPath, std::string& targetBranch, std::string& message);
    //GitAPIResponse gitMergeMultipleBranches(std::string& repoPath, std::vector<Branch> targetBranchs, std::string& message);
    GitAPIResponse gitStatus(std::string& repoPath);
    GitAPIResponse showGitObjectContents(std::string& repoPath, Sha1 hash);
    GitAPIResponse gitPull(std::string& repoPath, Remote& remote, Branch& branch);
    GitAPIResponse gitPush(std::string& repoPath, Remote& remote, Branch& branch);

}

#endif // GITAPI_H
