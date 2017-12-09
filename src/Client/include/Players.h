/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_

#include "Cell.h"
#include "Board.h"
#include <vector>

class Players {
public:
    /*
     * Constractur - the Players constractur.
     */
    Players(char symbol);

    /*
     * play - virtual function, the function ask the player to play
     * the move, each player in his way.
     */
    virtual Cell &play(Board &b, int &myScore, int &otherScore)=0;

    /*
    * getSymbol - return the symbol of the player.
    */
    char getSymbol() const;

    vector<Cell> &getMoves();

protected:
    vector<Cell> moves;
    char symbol, otherSymbol;
};

#endif /* PLAYERS_H_ */
