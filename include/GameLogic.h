//
// Created by eliyahu on 12/7/17.
//

#ifndef RAVERSI_GAMELOGIC_H
#define RAVERSI_GAMELOGIC_H

#include "Cell.h"
#include "Players.h"

class GameLogic {
public:
    GameLogic(int size);

    void deleteBoard();

    /*
     * generateMoves function check all the moves the player
     * can play and return it in vector of Cells.
     */
    void generateMoves(Players *player, vector<Cell> &vec, Board &b);

    /*
     * makeMove function set the move by the cell into the board.
     */
    void makeMove(Cell cell, int &myScore, int &otherScore, Players *player, Board &b);

    /*
     * changeCells function change all the vector cell to the new symbol.
     */
    void changeCells(vector<Cell> cellsToChange, int &myScore, int &otherScore, Players *player, Board &b);

    Board &getGameBoard();

private:
    Board *board;
};


#endif //RAVERSI_GAMELOGIC_H
