#include "sha1.h"

Sha1::Sha1() {
}

Sha1::Sha1(string initialString) : fullSha(initialString) {
}

string Sha1::getStringOfLength(int length) const {
    return this->fullSha.substr(0, length);
}

string Sha1::getFullString() const {
    return this->fullSha;
}
