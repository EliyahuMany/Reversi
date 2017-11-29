/*
 * Board.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: orian edri
 *      ID:308335454
 */

#include "Board.h"

Board::Board(int size) {
	this->size = size;
	this->board = new char *[size + 1];
	for (int i = 0; i < size + 1; ++i) {
		board[i] = new char[size + 1];
		for (int j = 0; j < size + 1; ++j) {
			board[i][j] = ' ';
		}
	}
	this->board[size / 2][size / 2] = 'o';
	this->board[(size / 2) + 1][size / 2] = 'x';
	this->board[(size / 2) + 1][(size / 2) + 1] = 'o';
	this->board[size / 2][(size / 2) + 1] = 'x';
}

Board &Board::makeCopy() {
	Board *b = new Board(this->getSize());
	for (int i = 0; i < size + 1; ++i) {
		for (int j = 0; j < size + 1; ++j) {
			b->board[i][j] = this->board[i][j];
		}
	}
	return *b;
}

void Board::print() {
	for (int i = 0; i <= this->size; i++) {
		for (int j = 0; j <= this->size; ++j) {
			if (i == 0 && j == 0) {
				if (this->getSize() >= 10) {
					cout << "  ";
				} else {
					cout << ' ';
				}
			} else if (i == 0) {
				cout << ' ';
				cout << j;
				if (j < 10) {
					cout << ' ';
				}
			} else if (j == 0) {
				if (this->getSize() >= 10) {
					if (i < 10) {
						cout << i << ' ';
					} else {
						cout << i;
					}
				} else {
					cout << i;
				}
			} else if (board[i][j] != ' ') {
				cout << ' ';
				cout << board[i][j];
				cout << ' ';
			} else {
				cout << "   ";
			}
			cout << "|";
		}
		cout << endl;
		if (this->getSize() >= 10) {
			cout << "---";
		} else {
			cout << "--";
		}
		for (int k = 0; k < this->getSize(); ++k) {
			cout << "----";
		}
		cout << endl;
	}

}

char** Board::getBoard() {
	return this->board;
}

int Board::getSize() {
	return this->size;
}

Board::~Board() {
	for (int i = 0; i < this->size; i++)
		delete[] board[i];
	delete[] board;
}
