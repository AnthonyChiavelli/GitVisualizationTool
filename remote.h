#ifndef REMOTE_H
#define REMOTE_H

#include <string>

using namespace std;

class Remote {

public:
    Remote(string& name, string& url);

private:
    string url;
    string name;
};

#endif // REMOTE_H
