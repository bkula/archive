#include "WebDelegate.h"

#define USE_WEBSOCKETS 1

WebDelegate* WebDelegate::client = nullptr;
WebDelegate* WebDelegate::server = nullptr;

WebDelegate::WebDelegate()
{
    //ctor
}

WebDelegate* WebDelegate::getServer()
{
    if (! server) {
        server = new WebDelegate();
    }
    return server;
}

WebDelegate* WebDelegate::getClient()
{
    if (! client) {
        client = new WebDelegate();
    }
    return client;
}

void WebDelegate::send(std::string message)
{
    DEB(message);
    DEB("ssss");
}
