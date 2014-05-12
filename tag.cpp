#include "tag.h"

Tag::Tag(CommitNode &commit, string &type, string &tag, string &tagger, string &message)
{
    this->commit = commit;
    this->type = type;
    this->tag = tag;
    this->tagger = tagger;
    this->message = message;
}

CommitNode Tag::getCommit() const
{
    return commit;
}

void Tag::setCommit(const CommitNode &value)
{
    commit = value;
}
string Tag::getType() const
{
    return type;
}

void Tag::setType(const string &value)
{
    type = value;
}
string Tag::getTag() const
{
    return tag;
}

void Tag::setTag(const string &value)
{
    tag = value;
}
string Tag::getTagger() const
{
    return tagger;
}

void Tag::setTagger(const string &value)
{
    tagger = value;
}
string Tag::getMessage() const
{
    return message;
}

void Tag::setMessage(const string &value)
{
    message = value;
}





