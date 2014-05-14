#include "gitapiresponse.h"

using namespace std;


GitAPIResponse::GitAPIResponse (bool isError, string &message){
  this->isError = isError;
  this->message =  message;
}

void GitAPIResponse::setError(bool& value){
  isError = value;
}

bool GitAPIResponse::getError() const{
  return isError;
}

string GitAPIResponse::getMessage() const{
  return message;
}




