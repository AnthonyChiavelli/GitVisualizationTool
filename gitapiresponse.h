#ifndef GITAPIRESPONSE_H
#define GITAPIRESPONSE_H

#include <string>

class GitAPIResponse
{
    private:
        bool isError;
        std::string message;

    public:
        GitAPIResponse ( bool isError, std::string& message);

        void setError(bool& value);
        bool getError() const;
        std::string getMessage() const;
};

#endif // GITAPIRESPONSE_H
