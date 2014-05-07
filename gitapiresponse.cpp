#include "gitapiresponse.h"

using namespace std;


    GitAPIResponse::GitAPIResponse (bool isError, string &message){
        GitAPIResponse::isError = isError;
        GitAPIResponse::message =  message;
    }

    void GitAPIResponse::setError(bool& value){
        GitAPIResponse::isError = value;
    }

    bool GitAPIResponse::getError() const{
        return GitAPIResponse::isError;
    }

    string GitAPIResponse::getMessage() const{
       return GitAPIResponse::message;
    }






