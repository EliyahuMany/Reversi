/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/Players.h"

Players::Players(char symbol, Print &printer) :
        symbol(symbol), printer(printer) {
}

char Players::getSymbol() const {
    return symbol;
}

vector<Cell> &Players::getMoves() {
    return moves;
}
