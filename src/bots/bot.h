#ifndef SRC_BOTS_BOT_H
#define SRC_BOTS_BOT_H

#include "server/server.h"

typedef void (*FBotTick)(CCollision *pCollision);

extern "C" {

void BotTick(CCollision *pCollision);
}

#endif
