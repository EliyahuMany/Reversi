//
// Created by eliyahu on 12/10/17.
//

#ifndef RAVERSI_CONSOLEPRINT_H
#define RAVERSI_CONSOLEPRINT_H

#include "Print.h"

class ConsolePrint : public Print {
public:
    ConsolePrint(Board board);

    void board();

    void winner(char sign);

    void draw();

    void playerTurn(char sign, vector<Cell> moves);

    void enterMoves();

    void aiTurn();

};


#endif //RAVERSI_CONSOLEPRINT_H
