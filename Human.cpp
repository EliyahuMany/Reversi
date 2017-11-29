/*
 * Player.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#include "Human.h"

Player::Player(char symbol) :
		symbol(symbol) {
	if (this->symbol == 'x')
		this->otherSymbol = 'o';
	else
		this->otherSymbol = 'x';
}

void Player::generateMoves(Board &b) {
	this->possibleMoves.clear();
	int size = b.getSize() - 1;
	char** board = b.getBoard();
	bool found;
	for (int i = 1; i < size + 1; i++) {
		for (int j = 1; j < size + 1; j++) {
			Cell c(i, j);
			found = false;
			if (i != size && board[i][j] == ' '
					&& board[i + 1][j] == this->otherSymbol) {
				Cell nextC(i + 1, j);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (board[i][j] == ' ' && board[i - 1][j] == this->otherSymbol) {
				Cell nextC(i - 1, j);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (j != size && board[i][j] == ' '
					&& board[i][j + 1] == this->otherSymbol) {
				Cell nextC(i, j + 1);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (board[i][j] == ' ' && board[i][j - 1] == this->otherSymbol) {
				Cell nextC(i, j - 1);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (i != size && j != size && board[i][j] == ' '
					&& board[i + 1][j + 1] == this->otherSymbol) {
				Cell nextC(i + 1, j + 1);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (board[i][j] == ' '
					&& board[i - 1][j - 1] == this->otherSymbol) {
				Cell nextC(i - 1, j - 1);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (i != size && board[i][j] == ' '
					&& board[i + 1][j - 1] == this->otherSymbol) {
				Cell nextC(i + 1, j - 1);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (j != size && board[i][j] == ' '
					&& board[i - 1][j + 1] == this->otherSymbol) {
				Cell nextC(i - 1, j + 1);
				if (c.checkIfAvailable(b, nextC, this->symbol))
					found = true;
			}
			if (found)
				possibleMoves.push_back(c);
		}
	}
}

void Player::play(Board &b, int &myScore, int &otherScore) {
	while (true) {
		cout << this->symbol << " is your turn." << endl;
		cout << "Your possible moves are: ";
		if (!this->possibleMoves.empty())
			for (unsigned int i = 0; i < this->possibleMoves.size(); i++)
				cout << "(" << this->possibleMoves[i].getX() << " , "
						<< this->possibleMoves[i].getY() << ") ";
		cout << "\n";
		cout << "Choose your cell(e.g: x y):  ";
		int x, y;
		cin >> x >> y;
		cin.clear();
		cin.ignore(100, '\n');
		int f = 0;
		for (unsigned int i = 0; i < this->possibleMoves.size(); i++) {
			if (this->possibleMoves[i].getX() == x
					&& this->possibleMoves[i].getY() == y) {
				b.getBoard()[x][y] = this->symbol;
				f = 1;
				this->flipCells(b, this->possibleMoves[i], myScore, otherScore);
				myScore++;
			}
		}
		if (f == 0)
			cout << "Wrong input!" << endl;
		else
			break;
	}
}

void Player::flipCells(Board &b, Cell chosenCell, int &myScore,
		int &otherScore) {
	vector<Cell> cellsToFlip = chosenCell.getCandidateForFlip();
	char** board = b.getBoard();
	for (unsigned int i = 0; i < cellsToFlip.size(); i++) {
		board[cellsToFlip[i].getX()][cellsToFlip[i].getY()] = this->symbol;
		myScore++;
		otherScore--;
	}
}
