#include "localrepoparser.h"
#include "gitapiresponse.h"
#include <iostream>
#include <fstream>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QStringListIterator>

#define PATH_TO_REFS "/refs/heads/"
#define PATH_TO_OBJECTS "/objects/"
#define SKIP_HIDDEN_FOLDERS 2
// git object line formats (for parsing)
#define FORMAT_COMMIT_PARENT ""

using namespace GitAPI;

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

CommitNode* parseCommitNode(CommitNode* commitNode, string& commitContents) {
    // Break the commit contents up line-by-line
    QStringList* lines = (new QString(commitContents))->split('\n');
    QStringListIterator* lineIterator = new QStringListIterator(lines);

    // Read through the contents of the commit
    while (lineIterator->hasNext()) {
        QString currentLine = lineIterator->next();

        if (currentLine != "\n") {
            QStringListIterator* tokenIterator = new QStringListIterator(currentLine.split(' '));
            while (tokenIterator->hasNext()) {
                QString currentToken = tokenIterator->next();
                if (currentToken == "tree") {
                    // Ignore the SHA-1 of the tree, since we aren't using them right now
                    tokenIterator->next();
                }
                else if (currentToken == "parent") {
                    // Get the SHA-1 of the parent commit
                    currentToken == tokenIterator->next();
                    //TODO: check for this commit in any existing tree
                    CommitNode *parent = new CommitNode(currentToken);
                    commitNode.addParent(parent);
                }
            }
        }
        else {
            // Get the commit message if there is any
            QString commitMessage = "";
            while (lineIterator->hasNext()) {
                commitMessage += lineIterator->next();
            }
            commitNode.setMessage(commitMessage);
        }
    }
}
