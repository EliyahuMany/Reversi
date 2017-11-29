/*
 * Player.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#include "Human.h"

Human::Human(char symbol) :
		Players(symbol) {
	this->symbol = symbol;
	if (this->symbol == 'x') {
		this->otherSymbol = 'o';
	} else {
		this->otherSymbol = 'x';
	}
}

int Human::play(Board &b, int &myScore, int &otherScore) {
	string choose;
	this->generateMoves(b, this->moves);
	if (!this->moves.empty()) {
		cout << this->symbol << ": It's your move." << endl;
		cout << "Your possible moves:";
		for (unsigned int i = 0; i < this->moves.size(); ++i) {
			Cell c = this->moves[i];
			cout << "(" << c.getX() << "," << c.getY() << ")";
		}
		cout << endl;
		while (true) {
			cout << "Please enter your move row,col: " << endl;
			cin >> choose;
			for (int i = 0; i < this->moves.size(); ++i) {
				if ((int) choose[0] - 48 == this->moves[i].getX()
						&& (int) choose[2] - 48 == this->moves[i].getY()) {
					this->makeMove(this->moves[i], myScore, otherScore, b);
					while (!this->moves.empty()) {
						this->moves.pop_back();
					}
					return 1;
				}
			}
			cout << "Wrong entry!" << endl;
		}
	} else {
		return 0;
	}
}

