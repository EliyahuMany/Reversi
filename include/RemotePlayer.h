//
// Created by orian on 12/9/17.
//

#ifndef RAVERSI_REMOTEPLAYER_H
#define RAVERSI_REMOTEPLAYER_H

#include "Players.h"
#include "Client.h"

class RemotePlayer : public Players {
public:
    RemotePlayer(char symbol, Client &client);

    Cell &play(Board &b, int &myScore, int &otherScore);

private:
    Client client;
    Cell cell;
};


#endif //RAVERSI_REMOTEPLAYER_H
