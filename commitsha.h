#ifndef COMMITSHA_H
#define COMMITSHA_H
#include <string>

using namespace std;

/*
 * Represents a SHA hash identifying a commit
 */
class CommitSha {

public:
    // Takes the full SHA stripng
    CommitSha(string);
    // n Character string representation
    string getStringOfLength(int);
    // Full string representation
    string getFullString();

private:
    // The full string representation
    string fullSha;
};

#endif // COMMITSHA_H
