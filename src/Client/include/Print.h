//
// Created by eliyahu on 12/10/17.
//

#ifndef RAVERSI_PRINT_H
#define RAVERSI_PRINT_H

#include "Cell.h"
#include "Board.h"
#include <string>

using namespace std;

class Print {
public:
    Print();

    virtual void board(Board &board) = 0;

    virtual void string(char *string) = 0;

    virtual void winner(char sign) = 0;

    virtual void playerTurn(char sign, vector<Cell> moves) = 0;

    virtual void connectionFailed(const char *m) = 0;

    virtual void played(char sign, char *cell) = 0;
};


#endif //RAVERSI_PRINT_H
