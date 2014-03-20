#include "repository.h"

Repository::Repository() {

}

Repository::Repository(CommitNode &initialCommit) {
    this->initialCommit = initialCommit;
}

CommitNode Repository::getInitialCommit() const
{
    return initialCommit;
}

void Repository::setInitialCommit(const CommitNode &value)
{
    initialCommit = value;
}

