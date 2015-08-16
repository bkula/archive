#ifndef __WEB_DELEGATE_H__
#define __WEB_DELEGATE_H__

#include "Common.h"

class WebDelegate
{
public:

    WebDelegate(std::string adress);

    std::string receive();
    void send(std::string message);

    static WebDelegate* getServer() { return getDelegate(0); }
    static WebDelegate* getClient() { return getDelegate(1); }

private:

    std::vector<PublicVar*> variables;

    static WebDelegate* delegate[2];
    static getDelegate(int i);
};

#endif // __WEB_DELEGATE_H__
