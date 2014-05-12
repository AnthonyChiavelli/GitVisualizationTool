#include "remote.h"
#include <string>

using namespace std;

Remote::Remote(string& name, string& url) {
    this->name = name;
    this->url = url;
}
string Remote::getUrl() const
{
    return url;
}

void Remote::setUrl(const string &value)
{
    url = value;
}
string Remote::getName() const
{
    return name;
}

void Remote::setName(const string &value)
{
    name = value;
}



