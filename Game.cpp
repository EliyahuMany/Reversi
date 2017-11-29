/*
 * Game.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#include "Game.h"

Game::Game(int size) :
		b(Board(size)), pX(Player('x')), pO(Player('o')) {
}

void Game::run() {
	int xScore = 2, oScore = 2;
	int flagX = 1, flagO = 1; //mark if X/O can play.
	while (flagX != 0 || flagO != 0) {
		flagX = 1;
		flagO = 1;
		this->pX.generateMoves(this->b);
		if (!this->pX.getPossibleMoves().empty()) {
			this->b.print();
			this->pX.play(this->b, xScore, oScore);
		} else
			flagX--;
		this->pO.generateMoves(this->b);
		if (!this->pO.getPossibleMoves().empty()) {
			this->b.print();
			this->pO.play(this->b, oScore, xScore);
		} else
			flagO--;
	}
	this->b.print();
	if (xScore > oScore)
		cout << "X is the winner!" << endl;
	else if (xScore < oScore)
		cout << "O is the winner!" << endl;
	else
		cout << "Draw" << endl;
}
