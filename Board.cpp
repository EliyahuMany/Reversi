/*
 * Board.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: orian edri
 *      ID:308335454
 */

#include "Board.h"

Board::Board(int size) {
	this->board = new char*[size];
	for (int i = 0; i < size; i++) {
		this->board[i] = new char[size];
	}
	this->size = size;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			board[i][j] = ' ';

		}
	}
	board[this->size / 2][this->size / 2] = 'o';
	board[this->size / 2 + 1][this->size / 2 + 1] = 'o';
	board[this->size / 2][this->size / 2 + 1] = 'x';
	board[this->size / 2 + 1][this->size / 2] = 'x';
}

void Board::print() const {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (i == 0 && j == 0) {
				cout << "  | ";
			} else if (j == 0) {
				if (i >= 10)
					cout << i << "| ";
				else
					cout << i << " | ";
			} else if (i == 0) {
				cout << j << " | ";
			} else {
				cout << board[i][j] << " | ";
			}
		}
		cout << '\n';
		if (this->size == 7)
			cout << "--------------------------" << endl;
		else if (this->size == 9)
			cout << "----------------------------------" << endl;
		else
			cout << "------------------------------------------" << endl;
	}
}

char** Board::getBoard() const {
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
