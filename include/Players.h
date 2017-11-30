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
     * generateMoves function check all the moves the player
     * can play and return it in vector of Cells.
     */
    void generateMoves(Board &b, vector<Cell> &vec);

    /*
     * makeMove function set the move by the cell into the board.
     */
    void makeMove(Cell cell, int &myScore, int &otherScore, Board &b);

    /*
     *
     */
    void changeCells(vector<Cell> cellsToChange, int &myScore, int &otherScore,
                     Board &b);

    /*
     * play - virtual function, the function ask the player to play
     * the move, each player in his way.
     */
    virtual int play(Board &b, int &myScore, int &otherScore)=0;

    /*
    * getSymbol - return the symbol of the player.
    */
    char getSymbol() const;

protected:
    vector<Cell> moves;
    char symbol, otherSymbol;
};

#endif /* PLAYERS_H_ */
