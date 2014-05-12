#ifndef GITUSER_H
#define GITUSER_H
#include <QString>

using namespace std;

class GitUser {

public:
    GitUser();
    GitUser(QString& name, QString& email);

    QString getName() const;
    void setName(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

private:
    QString name;
    QString email;
};

#endif // GITUSER_H
