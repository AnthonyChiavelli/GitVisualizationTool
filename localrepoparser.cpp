#include "localrepoparser.h"

#include <iostream>
#include <fstream>
#include <QFile>
#include <QByteArray>

#define READ_ONLY "r"

Branch& LocalRepoParser::getBranch(std::string &pathToGitFolder, std::string &branchName) {
    Branch branch;
    string branchFileContents;

    // Get the branch file contents
    string const& filePathToBranch(pathToGitFolder + "/refs/heads/" + branchName);
    ifstream in(filePathToBranch.c_str(), ios::binary);
    getline(in, branchFileContents);
    cout << "Branch name: " << branchName;
    cout << "Branch file contents (commit SHA): " << branchFileContents << "\n";

    branch.setName(branchName);
    branch.setCommitSHA(branchFileContents);
    branch.setType(LOCAL_BRANCH);

    return branch;
}
