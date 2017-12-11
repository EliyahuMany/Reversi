/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/Board.h"

Board::Board(int size) {
	this->size = size;
	this->board = new char *[size + 1];
	for (int i = 0; i < size + 1; ++i) {
		board[i] = new char[size + 1];
		for (int j = 0; j < size + 1; ++j) {
			board[i][j] = ' ';
		}
	}
	this->board[size / 2][size / 2] = 'O';
	this->board[(size / 2) + 1][size / 2] = 'X';
	this->board[(size / 2) + 1][(size / 2) + 1] = 'O';
	this->board[size / 2][(size / 2) + 1] = 'X';
}

void Board::makeCopy(Board &bCopy) {
	for (int i = 0; i < size + 1; ++i) {
		for (int j = 0; j < size + 1; ++j) {
			bCopy.getBoard()[i][j] = this->board[i][j];
		}
	}
}

char** Board::getBoard() {
	return this->board;
}

int Board::getSize() {
	return this->size;
}

Board::~Board() {
	for (int i = 0; i < this->size + 1; i++)
		delete[] board[i];
	delete[] board;
}
