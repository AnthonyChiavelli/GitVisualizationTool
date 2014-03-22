#ifndef GITOBJECT_H
#define GITOBJECT_H

#include <string>

using namespace std;

class GitObject {

public:
    GitObject();
    GitObject(string& SHA1);

    string getSHA1() const;
    void setSHA1(const string &value);

    // Returns the name of the subdirectory in which this git object is located
    // (first two characters in SHA1)
    string getSubdirectoryName() const;

    // Returns the filename of this git object (last 38 characters in SHA1)
    string getFileName() const;


private:
    string SHA1;
};

#endif // GITOBJECT_H
