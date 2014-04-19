#include "localrepoparser.h"

#include <iostream>
#include <fstream>
#include <QDir>
#include <QString>
#include <QStringList>

#define PATH_TO_REFS "/refs/heads/"
#define PATH_TO_OBJECTS "/objects/"

#define SKIP_HIDDEN_FOLDERS 2

// Create hashmap for storing a record of all commits encountered (to prevent duplication)
static QHash<string, CommitNode *> *commits;
string absPathToGitFolder;

CommitNode* LocalRepoParser::getGitTree(string const &pathToGitFolder) {
    QStringList branchNames;
    vector<Branch *> branches;
    absPathToGitFolder = pathToGitFolder;

    // Get a list of all the local branches
    QDir branchDirectory((pathToGitFolder + PATH_TO_REFS).c_str());
    branchNames = branchDirectory.entryList();
    for(int i = SKIP_HIDDEN_FOLDERS; i < branchNames.length(); i++) {
        branches.push_back(getBranch(pathToGitFolder, branchNames.at(i).toStdString()));
    }

    // Assemble the commit history of each branch into a single CommitNode
    if (branches.size() > 0) {
        getCommitHistory(branches.at(0)->getCommitSha());
    }
}

Branch* LocalRepoParser::getBranch(string const &pathToGitFolder, string const &branchName) {
//    Branch branch;
    string branchFileContents;

    // Get the branch file contents
    string const& filePathToBranch(pathToGitFolder + "/refs/heads/" + branchName);
    ifstream in(filePathToBranch.c_str(), ios::binary);
    getline(in, branchFileContents);
    cout << "Branch name: " << branchName;
    cout << ", Branch file contents (commit SHA): " << branchFileContents << endl;

    // Create a branch with the contents of the branch file
    Branch *branch = new Branch();
    branch->setName(branchName);
    branch->setCommitSha(branchFileContents);
    branch->setType(LOCAL_BRANCH);

    return branch;
}

CommitNode* LocalRepoParser::getCommitHistory(Sha1 const &commitSha, CommitNode *childCommit,
                                              QHash<string, CommitNode *> *commits) {
    // Create a CommitNode* for the given sha
    CommitNode *currentCommit = new CommitNode();
    currentCommit->setSha1(commitSha.getFullString());

    // Get the contents of the commit file

    // ...and parse its contents into a commit object


    // Add the child to the commit

    // if commit has parents
        // get commit history for each parent
    // else return a new CommitNode

}

// Returns true if the given string is the next token
bool have(string &token) {
}

CommitNode* parseCommitNode() {

}
