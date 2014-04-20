#include "localrepoparser.h"
#include "gitapiresponse.h"
#include "gitapi.h"
#include "sha1.h"
#include <iostream>
#include <fstream>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QStringListIterator>

#define PATH_TO_REFS "/.git/refs/heads/"
#define PATH_TO_OBJECTS "/.git/objects/"
#define SKIP_HIDDEN_FOLDERS 2
// git object line formats (for parsing)
#define FORMAT_COMMIT_PARENT ""

// Parses the contents of a commit object
void parseCommitNode(CommitNode* commitNode, string& commitContents);
// Returns the full history for the given commit (identified by it's SHA-1)
void getCommitHistory(Sha1 const &commitSha, CommitNode *childCommit = NULL, QHash<string, CommitNode *> *commits = NULL);

// Create hashmap for storing a record of all commits encountered (to prevent duplication)
static QHash<string, CommitNode *> *commits;
string absPathToGitFolder;
CommitNode *rootCommit;

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
        cout << "Branch commit Sha: " << branches.at(0)->getCommitSha().getFullString() << endl;
        getCommitHistory(branches.at(0)->getCommitSha());
    }
}

Branch* LocalRepoParser::getBranch(string const &pathToGitFolder, string const &branchName) {
//    Branch branch;
    string branchFileContents;

    // Get the branch file contents
    string const& filePathToBranch(pathToGitFolder + PATH_TO_REFS + branchName);
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

void getCommitHistory(Sha1 const &commitSha, CommitNode *childCommit, QHash<string, CommitNode *> *commits) {
    // Create a CommitNode* for the given sha
    CommitNode *currentCommit = new CommitNode();
    currentCommit->setSha1(commitSha);

    // Get the contents of the commit file
    string commitContents = GitApi::showGitObjectContents(absPathToGitFolder, commitSha).getMessage();

    // ...and parse its contents into a commit object
    parseCommitNode(currentCommit, commitContents);

    // Add child to the commit if any
    if (childCommit != NULL) {
        currentCommit->addChild(childCommit);
    }

    // Get the commit history for each parent
    if (!currentCommit->getParents()->empty()) {
        // get commit history for each parent
        for (CommitNode * parent : *(currentCommit->getParents())) {
            getCommitHistory(parent->getSha1(), currentCommit);
        }
    }
    else { // Root commit
        // Save the root commit if it hasn't been saved already
        if (rootCommit == NULL) {
           rootCommit = currentCommit;
        }
    }

}

void parseCommitNode(CommitNode* commitNode, string& commitContents) {
    // Break the commit contents up line-by-line
    QStringList lines = (new QString(commitContents.c_str()))->split('\n');
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
                    currentToken = tokenIterator->next();
                    //TODO: check for this commit in any existing tree
                    Sha1 parentSha(currentToken.toStdString());
                    CommitNode *parent = new CommitNode(parentSha);
                    commitNode->addParent(parent);
                }
            }
        }
        else {
            // Get the commit message if there is any
            QString commitMessage = "";
            while (lineIterator->hasNext()) {
                commitMessage += lineIterator->next();
            }
            commitNode->setMessage(commitMessage.toStdString());
        }
    }
}
