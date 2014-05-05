#include "github/githubrepoparser.h"
#include "sha1.h"
#include <map>
#include <iostream>
#include <QHash>

#define API_REPO_URL "https://api.github.com/repos/"

void parseCommitNode(CommitNode *commitNode, string &commitContents, map<string, CommitNode *> *commitsEncountered);
void getCommitHistory(Sha1 const &commitSha, QHash<string, CommitNode *> *commits, CommitNode *childCommit);
bool seeEmail(string const &token);
string parseEmail(string const &token);

static CommitNode * rootCommit;

CommitNode* GithubRepoParser::getGitTree(string const &url) {
    /*map<string, string> apiBranches = GithubWebApi::parseBranches("AnthonyReid99", "master");
    QHash<QString, CommitNode*> *commits = new QHash<QString, CommitNode*>();

    vector<Branch *> branches;
    for(pair<string, string> s : apiBranches) {
        Sha1 *sha = new Sha1(s.second);
        Branch * branch = new Branch();
        branch->setName(s.first);
        branch->setCommitSha(*sha);
        branch->setType(REMOTE_BRANCH);
        branches.push_back(branch);
    }

    for (Branch *branch : branches) {
        cout << "Branch's commit Sha: " << branch->getCommitSha().getStringOfLength(7) << endl;
  //      getCommitHistory(branch->getCommitSha(), commits);
    }
*/
    return rootCommit;

}
/*
Branch* GithubRepoParser::getBranch(string const &url, string const &branchName);
    pair<string, string> apiBranch = GithubWebApi::parseBranch(url);
    Sha1 *sha = new Sha1(apiBranch.second);
    Branch * branch = new Branch();
    branch->setName(apiBranch.first);
    branch->setCommitSha(*sha);
    branch->setType(REMOTE_BRANCH);
    return branch;
}

void getCommitHistory(Sha1 const &commitSha, QHash<QString, CommitNode *> *commits, CommitNode *childCommit = NULL) {
    QString shaString(commitSha.getFullString().c_str());
    if (!commits->contains(shaString)) {
        CommitNode *currentCommit = new CommitNode();
        currentCommit->setSha1(commitSha);
        commits->insert(shaString, currentCommit);

        // ...and parse its contents into a commit object
        GithubWebApi::parseCommitNode(shaString.toStdString(), "AnthonyReid99", "master", currentCommit);

        // Add child to the commit if any
        if (childCommit != NULL) {
            currentCommit->addChild(childCommit);
        }

        // Get the commit history for each parent
        if (!currentCommit->getParents()->empty()) {
            // get commit history for each parent
            for (CommitNode * parent : *(currentCommit->getParents())) {
                getCommitHistory(parent->getSha1(), commits, currentCommit);
            }
        }
        else { // Root commit
            // Save the root commit if it hasn't been saved already
            if (rootCommit == NULL) {
               rootCommit = currentCommit;
            }
        }
    }
}
*/
