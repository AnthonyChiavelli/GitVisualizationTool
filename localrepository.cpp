#include "localrepository.h"

LocalRepository::LocalRepository(string &absolutePath, vector<Remote> remotes)
{
    this->absolutePath = absolutePath;
    this->remotes = remotes;
}

string LocalRepository::getAbsolutePath() const
{
    return absolutePath;
}

void LocalRepository::setAbsolutePath(const string &value)
{
    absolutePath = value;
}
vector<Remote> LocalRepository::getRemotes() const
{
    return remotes;
}

void LocalRepository::setRemotes(const vector<Remote> &value)
{
    remotes = value;
}


