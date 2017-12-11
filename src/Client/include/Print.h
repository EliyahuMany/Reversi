/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_PRINT_H
#define RAVERSI_PRINT_H

#include "Cell.h"
#include "Board.h"
#include <string>

using namespace std;

class Print {
public:

    /**
     * Constractur to the Print.
     */
    Print();

    /**
     * virtual function, print the board
     * @param board board of the game.
     */
    virtual void board(Board &board) = 0;

    /**
     * virtual function, print the string.
     * @param string the string to print.
     */
    virtual void string(char *string) = 0;

    /**
     * virtual function, print the winner.
     * @param sign the winner sign.
     */
    virtual void winner(char sign) = 0;

    /**
     * virtual function, print the turn of the player.
     * @param sign the sing of the player.
     * @param moves the vector of the moves.
     */
    virtual void playerTurn(char sign, vector<Cell> moves) = 0;

    /**
     * virtaul function, print the connection failed massage.
     * @param m the massage.
     */
    virtual void connectionFailed(const char *m) = 0;

    /**
     * virtual function, the remote player move.
     * @param sign the sing of the player.
     * @param cell the cell who played.
     */
    virtual void played(char sign, char *cell) = 0;
};


#endif //RAVERSI_PRINT_H
