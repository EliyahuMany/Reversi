/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "../include/Human.h"

Human::Human(char symbol, Print &printer) :
        Players(symbol, printer), cell(Cell()) {
    this->symbol = symbol;
    if (this->symbol == 'X') {
        this->otherSymbol = 'O';
    } else {
        this->otherSymbol = 'X';
    }
}

Cell &Human::play(Board &b, int &myScore, int &otherScore) {
    string choose;

    if (this->getMoves().empty()) {
        return this->cell;
    }
    this->printer.playerTurn(this->symbol, this->moves);
    while (true) {
        this->printer.string((char *) "Please enter your move row,col: ");
        cin >> choose;
        for (int i = 0; i < this->moves.size(); ++i) {
            if ((int) choose[0] - 48 == this->moves[i].getX()
                && (int) choose[2] - 48 == this->moves[i].getY()) {
                while (!this->moves.empty()) {
                    this->moves.pop_back();
                }
                return this->moves[i];
            }
        }
        this->printer.string((char *) "Wrong entry!");
    }
}