/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_REMOTEPLAYER_H
#define RAVERSI_REMOTEPLAYER_H

#include "Players.h"
#include "Client.h"

class RemotePlayer : public Players {
public:

    /**
     * Constractur
     * @param symbol the sign of the player.
     * @param client the client.
     * @param printer the printer.
     */
    RemotePlayer(char symbol, Client &client, Print &printer);

    /**
     * receive noMove / Cell from the server and play according the returned value.
     * @param b the board of the game.
     * @param myScore score of the remote player.
     * @param otherScore score of the local player.
     * @return Cell the remote player Choosed / noMove.
     */
    Cell &play(Board &b, int &myScore, int &otherScore);

private:
    Client client;
    Cell cell;
};


#endif //RAVERSI_REMOTEPLAYER_H
