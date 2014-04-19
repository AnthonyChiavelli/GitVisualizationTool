#ifndef GITUSER_H
#define GITUSER_H
#include <string>

using namespace std;

class GitUser {

public:
    GitUser();
    GitUser(string& name, string& email);

    string getName() const;
    void setName(const string &value);

    string getEmail() const;
    void setEmail(const string &value);

private:
    string name;
    string email;
};

#endif // GITUSER_H