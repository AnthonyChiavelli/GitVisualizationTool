#include "gitobject.h"

GitObject::GitObject() {

}

GitObject::GitObject(string &sha1) : sha1(sha1)  {
}

Sha1 GitObject::getSha1() const {
    return sha1.getFullString();
}

void GitObject::setSha1(Sha1 const &value) {
    sha1 = value;
}

string GitObject::getSubdirectoryName() const {
    return sha1.getStringOfLength(2) + "/";
}

string GitObject::getFileName() const {
    return sha1.getFullString().substr(2, 38);
}



