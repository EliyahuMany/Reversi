/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_CONSOLEPRINT_H
#define RAVERSI_CONSOLEPRINT_H

#include "Print.h"

using namespace std;

class ConsolePrint : public Print {
public:
    /**
     * Constractur to ConsolePrint.
     */
    ConsolePrint();

    /**
     * print the board.
     * @param board the board
     */
    void board(Board &board);

    /**
     * print the string on the screen.
     * @param string the string to print.
     */
    void string(char *string);

    /**
     * print the winner on the screen.
     * @param sign the winner sign.
     */
    void winner(char sign);

    /**
     * print the vector moves/
     * @param sign the sign of the player.
     * @param moves the vector of cells.
     */
    void playerTurn(char sign, vector<Cell> moves);

    /**
     * print the connection failed on the screen/
     * @param m massage.
     */
    void connectionFailed(const char *m);

    /**
     * print the other player played move.
     * @param sign the player who played.
     * @param cell the choosed cell.
     */
    void played(char sign, char *cell);
};


#endif //RAVERSI_CONSOLEPRINT_H
