/*
 * Cell.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#include "../include/Cell.h"

Cell::Cell(int x, int y) {
	this->x = x;
	this->y = y;
}
int Cell::getX() {
	return this->x;
}
int Cell::getY() {
	return this->y;
}

bool Cell::checkIfAvailable(Board &b, Cell nextC, char player) {
	char** board = b.getBoard();
	int count = 0;
	for (int i = nextC.getX(), j = nextC.getY();
			(i < b.getSize() && i > 0) && (j < b.getSize() && j > 0);
			i += nextC.getX() - this->x, j += nextC.getY() - this->y) {
		if (board[i][j] == ' ')
			break;
		if (board[i][j] == player) {
			return true;
		}
		count++;
		this->candidateForFlip.push_back(Cell(i, j));
	}
	for (int i = 0; i < count; i++)
		this->candidateForFlip.pop_back();
	return false;
}

vector<Cell>& Cell::getCandidateForFlip() {
	return this->candidateForFlip;
}
