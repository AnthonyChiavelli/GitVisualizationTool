#include "githubwebapi.h"
#include "gituser.h"
#include <iostream>
extern "C" {
#include <curl/curl.h>
}
#include <QUrl>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>
#include <fstream>
#include <QJsonParseError>
#include <QStringList>
#define HOST "https://api.github.com/"

using namespace std;
size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up);
void initApi();
GitUser *parseAuthor();

CURL *curl;
struct curl_slist *slist=NULL;
static QString data;

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{

    for (int c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb;
}

void apiInit() {
    data.clear();
    curl = curl_easy_init();
    curl_global_init(CURL_GLOBAL_ALL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    slist = curl_slist_append(slist, "Accept: application/vnd.github.full+json");
    slist = curl_slist_append(slist, "User-Agent: GitVisualV1.0");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
}

GitUser* GitHubWebApi::validUser(char *usr, char *pass) {
    apiInit();
    string url = HOST;
    url += "users/";
    url += usr;
    char * aceUrl = new char[url.size()+1];
    copy(url.begin(), url.end(), aceUrl);
    aceUrl[url.size()] = '\0';
    curl_easy_setopt(curl, CURLOPT_URL, aceUrl);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, pass);
    curl_easy_setopt(curl, CURLOPT_USERNAME, usr);
    curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    int i = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    data.push_back("\0");

    QJsonParseError *j = new QJsonParseError();
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8(), j);
    cout << j->errorString().toStdString() <<endl;
    QJsonObject obj = doc.object();
    if(!obj.keys().contains("login")) {
        QString u = obj["login"].toString();
        QString e = obj["login"].toString();
        return new GitUser(u, e);
    }
    else return 0;
}

QHash<pair<string, string>, QString>* GitHubWebApi::parseBranches(string usr, string repo) {
    string const fname = "{\"name\":";
    string const fsha = "\"commit\":{\"sha\":";
    QHash<pair<string, string>, QString> * branches = new QHash<pair<string, string>, QString>();
    usr = HOST+usr+"/"+repo+"/branches";
    char * url = new char[usr.size()+1];
    copy(usr.begin(), usr.end(), url);
    url[usr.size()]='\0';
    apiInit();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_perform(curl);

    /*for(int i = data.find(fname), j = i+fname.size()+1; i>0; i=data.find(fname, i), j=i+fname.size()+1) {
        i = j+1;
        for(;data.at(i) != '\"'; i++);
        string name = data.substr(j, i-j);
        i = data.find(fsha, i);
        j = i>0 ? i+fsha.size()+1 : i;
        i = j+1;
        for(;data.at(i) != '\"'; i++);
        //branches->insert(pair<string, string>(data.substr(j, i-j), name));
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
*/
    return branches;
}

void GitHubWebApi::parseCommitNode(string sha, string usr, string repo, CommitNode *commit) {
    usr = HOST+usr+"/"+repo+"/commits/"+sha;
    char * url = new char[usr.size()+1];
    copy(usr.begin(), usr.end(), url);
    url[usr.size()]='\0';
    apiInit();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_perform(curl);
    commit->setAuthor(*parseAuthor());
}

GitUser *parseAuthor() {
    /*int i = data.find("author\":{\"name\":");
    int j = i += 17;
    while(data.at(j) != '\"')
        j++;
    QString author = data.substr(i, j).c_str();
    j = data.find("email\":", j);
    i = j += 7;
    while(data.at(j) != '\"')
        j++;
    QString email = data.substr(i, j).c_str();
    cout << author.toStdString() << " : " << email.toStdString() << endl;
    return new GitUser(author, email);
*/
}

void parseEmail() {

}
