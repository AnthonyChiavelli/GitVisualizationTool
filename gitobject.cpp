#include "gitobject.h"

GitObject::GitObject() {

}

GitObject::GitObject(string &sha1) : sha1(sha1)  {
    this->sha1 = sha1;
}

string GitObject::getSha1() const {
    return sha1.getFullString();
}

void GitObject::setSha1(const string &value) {
    sha1 = value;
}

string GitObject::getSubdirectoryName() const {
    return sha1.getStringOfLength(2) + "/";
}

string GitObject::getFileName() const {
    return sha1.getFullString().substr(2, 38);
}



