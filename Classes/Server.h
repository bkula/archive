#ifndef __SERVER_H__
#define __SERVER_H__

#include "WebDelegate.h"

class Server
{
public:

    Server();

    void update(float delta);

private:

    const int webId = 0;

    enum GAME_STATUS
    {
        GAME_STATUS_OPEN,
        GAME_STATUS_RUNNING,
        GAME_STATUS_STOPPED,
        GAME_STATUS_CLOSED,
        GAME_STATUS_SIZE
    };

    PublicVar<int> gameStatus;
    PublicVar<int> nextPlayerId;
};

#endif // __SERVER_H__
