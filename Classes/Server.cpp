#include "Server.h"

Server::Server()
{
    WebDelegate::getServer()->send("x");
}
