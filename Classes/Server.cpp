#include "Server.h"

Server::Server()
: gameStatus(webId, "game_status", GAME_STATUS_OPEN)
, nextPlayerId(webId, "next_player_id", 1)
{
    //WebDelegate::getServer()->send("x");
}

void Server::update(float deleta)
{
    //
}
