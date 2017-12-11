//
// Created by orian on 12/9/17.
//

#ifndef RAVERSI_LOCALPLAYER_H
#define RAVERSI_LOCALPLAYER_H


#include "Players.h"
#include "Client.h"

class LocalPlayer : public Players {
public:
    LocalPlayer(char symbol, Client &client, Print &printer);

    virtual Cell &play(Board &b, int &myScore, int &otherScore);

private:
    Client client;
    Cell cell;
};


#endif //RAVERSI_LOCALPLAYER_H
