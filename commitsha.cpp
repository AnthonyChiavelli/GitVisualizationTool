#include "commitsha.h"

CommitSha::CommitSha(string initialString) : fullSha(initialString) {
}

string CommitSha::getStringOfLength(int length) {
    return this->fullSha.substr(0, length);
}

string CommitSha::getFullString() {
    return this->fullSha;
}
