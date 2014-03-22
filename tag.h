#ifndef TAG_H
#define TAG_H

#include <string>
#include "commitnode.h"
#include "gitobject.h"

using namespace std;

class Tag : GitObject {

public:
    Tag(CommitNode &commit, string &type, string &tag, string &tagger, string &message);

    CommitNode getCommit() const;
    void setCommit(const CommitNode &value);

    string getType() const;
    void setType(const string &value);

    string getTag() const;
    void setTag(const string &value);

    string getTagger() const;
    void setTagger(const string &value);

    string getMessage() const;
    void setMessage(const string &value);

private:
    CommitNode commit;
    string type;
    string tag;
    string tagger;
    string message;
};

#endif // TAG_H
