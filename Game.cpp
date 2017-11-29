/*
 * Game.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#include "Game.h"

Game::Game(int size) :
		b(Board(size)), pX(new Human('x')), pO(new AIPlayer('o')) {
}

void Game::run() {
	int xScore = 2, oScore = 2;
	int flagX = 1, flagO = 1; //mark if X/O can play.
	this->b.print();
	while (flagX != 0 || flagO != 0) {
		flagX = pX->play(this->b, xScore, oScore);
		if (flagX) {
			this->b.print();
		}
		flagO = pO->play(this->b, oScore, xScore);
		if (flagO) {
			this->b.print();
		}
	}
	if (xScore > oScore)
		cout << "X is the winner!" << endl;
	else if (xScore < oScore)
		cout << "O is the winner!" << endl;
	else
		cout << "Draw" << endl;
}
