#ifndef GITOBJECT_H
#define GITOBJECT_H

#include "sha1.h"

using namespace std;

class GitObject {

public:
    GitObject();
    GitObject(string& sha1);

    Sha1 getSha1() const;
    void setSha1(Sha1 const &value);

    // Returns the name of the subdirectory in which this git object is located
    // (first two characters in SHA1)
    string getSubdirectoryName() const;

    // Returns the filename of this git object (last 38 characters in SHA1)
    string getFileName() const;


private:
    Sha1 sha1;  // SHA-1 hash value used to identify git object
};

#endif // GITOBJECT_H
