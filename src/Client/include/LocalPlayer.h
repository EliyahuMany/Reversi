/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_LOCALPLAYER_H
#define RAVERSI_LOCALPLAYER_H


#include "Players.h"
#include "Client.h"

class LocalPlayer : public Players {
public:

    /**
     * Constractur.
     *
     * @param symbol the symbol of the player.
     * @param client the client.
     * @param printer the printer of the game.
     */
    LocalPlayer(char symbol, Client &client, Print &printer);

    /**
     * choose the cell,send it to the server and return to the game board.
     * @param b the board
     * @param myScore the local player score.
     * @param otherScore the remote player score.
     * @return Cell, the choose of the player.
     */
    virtual Cell &play(Board &b, int &myScore, int &otherScore);

private:
    Client client;
    Cell cell;
};


#endif //RAVERSI_LOCALPLAYER_H
