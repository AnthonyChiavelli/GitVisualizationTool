#include "gituser.h"

GitUser::GitUser() {

}

GitUser::GitUser(string& name, string& email) {
    this->name = name;
    this->email = email;
}
string GitUser::getName() const
{
    return name;
}

void GitUser::setName(const string &value)
{
    name = value;
}
string GitUser::getEmail() const
{
    return email;
}

void GitUser::setEmail(const string &value)
{
    email = value;
}


