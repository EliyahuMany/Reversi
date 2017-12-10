//
// Created by eliyahu on 12/10/17.
//

#ifndef RAVERSI_PRINT_H
#define RAVERSI_PRINT_H

#include "Cell.h"
#include "Board.h"

class Print {
public:
    Print(Board &gameBoard);

    virtual void board() = 0;

    virtual void winner(char sign) = 0;

    virtual void draw() = 0;

    virtual void playerTurn(char sign, vector<Cell> moves) = 0;

    virtual void enterMoves() = 0;

    virtual void aiTurn() = 0;

protected:
    Board gameBoard;
};


#endif //RAVERSI_PRINT_H
