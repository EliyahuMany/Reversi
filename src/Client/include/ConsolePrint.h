//
// Created by eliyahu on 12/10/17.
//

#ifndef RAVERSI_CONSOLEPRINT_H
#define RAVERSI_CONSOLEPRINT_H

#include "Print.h"

using namespace std;

class ConsolePrint : public Print {
public:
    ConsolePrint();

    void board(Board &board);

    void string(char *string);

    void winner(char sign);

    void playerTurn(char sign, vector<Cell> moves);

    void connectionFailed(const char *m);

    void played(char sign, char *cell);
};


#endif //RAVERSI_CONSOLEPRINT_H
