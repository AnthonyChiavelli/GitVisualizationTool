#ifndef REMOTE_H
#define REMOTE_H

#include <string>

using namespace std;

class Remote {

public:
    Remote(string& name, string& url);

    string getUrl() const;
    void setUrl(const string &value);

    string getName() const;
    void setName(const string &value);

private:
    string url;
    string name;
};

#endif // REMOTE_H
