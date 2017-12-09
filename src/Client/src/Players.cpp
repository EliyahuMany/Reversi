/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "../include/Players.h"

Players::Players(char symbol) :
        symbol(symbol) {
}

char Players::getSymbol() const {
    return symbol;
}

vector<Cell> &Players::getMoves() {
    return moves;
}
