/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Board.h"
#include "Cell.h"
#include "Players.h"
#include "GameLogic.h"

class AIPlayer : public Players {
public:
    /*
     * Constractur - create the Ai player.
     */
    AIPlayer(char symbol, GameLogic gl);

    /*
     * play function connect between the player and the functions
     * to check which move is the best.
     */
    Cell &play(Board &b, int &myScore, int &otherScore);

    /*
     * checkMove function check what is the worst case when the AI
     * play the move curCell.
     */
    int checkMove(Board &b, int &myScore, int &otherScore, Cell curCell);

    /*
     * curMoveScore function get a board and return the worst case
     * score when the other player choose is best move.
     */
    int curMoveScore(Cell cell, int &myScore, int &otherScore, Board &b);

    /*
     * changeSymbolForRival - change the symbol of the AI
     * then the AI can check the rival moves.
     */
    void changeSymbolForRival();

private:
    GameLogic gl;
    Cell cell;
};

#endif /* AIPLAYER_H_ */
