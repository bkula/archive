#ifndef __WEB_DELEGATE_H__
#define __WEB_DELEGATE_H__

#include "Common.h"
#include "PublicVar.h"

class WebDelegate
{
public:

    WebDelegate();

    std::string receive();
    void send(std::string message);

    static WebDelegate* getServer();
    static WebDelegate* getClient();

private:

    std::vector<PublicVar*> variables;

    static WebDelegate* client;
    static WebDelegate* server;
};

#endif // __WEB_DELEGATE_H__
