#include "gitobject.h"

GitObject::GitObject() {

}

GitObject::GitObject(string &SHA1) {
    this->SHA1 = SHA1;
}

string GitObject::getSHA1() const {
    return SHA1;
}

void GitObject::setSHA1(const string &value) {
    SHA1 = value;
}

string GitObject::getSubdirectoryName() const {
    return SHA1.substr(0, 2);
}

string GitObject::getFileName() const {
    return SHA1.substr(2, 38);
}



