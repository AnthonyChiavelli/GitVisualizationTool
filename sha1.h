#ifndef COMMITSHA_H
#define COMMITSHA_H
#include <string>

using namespace std;

/*
 * Represents a SHA-1 hash
 */
class Sha1 {

public:
    Sha1();
    // Takes the full SHA string
    Sha1(string);
    // n Character string representation
    string getStringOfLength(int) const;
    // Full string representation
    string getFullString() const;

private:
    // The full string representation
    string fullSha;
};

#endif // COMMITSHA_H
