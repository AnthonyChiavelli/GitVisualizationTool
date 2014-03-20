#include "remote.h"

Remote::Remote(string& name, string& url) {
    this->name = name;
    this->url = url;
}

string& Remote::name() {
    return name;
}

void Remote::name(string& name){
    this->name = name;
}

string& Remote::url() {
    return url;
}

void Remote::url(string& url) {
    this->url = url;
}
