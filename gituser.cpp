#include "gituser.h"

GitUser::GitUser() {

}

GitUser::GitUser(QString& name, QString& email) {
    this->name = name;
    this->email = email;
}
QString GitUser::getName() const
{
    return name;
}

void GitUser::setName(const QString &value)
{
    name = value;
}
QString GitUser::getEmail() const
{
    return email;
}

void GitUser::setEmail(const QString &value)
{
    email = value;
}


