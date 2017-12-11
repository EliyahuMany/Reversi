/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_GAMELOGIC_H
#define RAVERSI_GAMELOGIC_H

#include "Cell.h"
#include "Players.h"

class GameLogic {
public:

    /**
     * Constractur
     * @param size the size of the board.
     */
    GameLogic(int size);

    /**
     * delete the board.
     */
    void deleteBoard();

    /*
     * generateMoves function check all the moves the player
     * can play and return it in vector of Cells.
     */
    void generateMoves(Players *player, vector<Cell> &vec, Board &b);

    /*
     * makeMove function set the move by the cell into the board.
     */
    int makeMove(Cell cell, int &myScore, int &otherScore, Players *player, Board &b);

    /*
     * changeCells function change all the vector cell to the new symbol.
     */
    void changeCells(vector<Cell> cellsToChange, int &myScore, int &otherScore, Players *player, Board &b);

    /**
     * @return the game board.
     */
    Board &getGameBoard();

private:
    Board *board;
};


#endif //RAVERSI_GAMELOGIC_H
