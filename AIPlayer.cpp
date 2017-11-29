/*
 * AIPlayer.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#include "AIPlayer.h"

AIPlayer::AIPlayer(char symbol) :
		Players(symbol) {
	this->symbol = symbol;
	if (this->symbol == 'x') {
		this->otherSymbol = 'o';
	} else {
		this->otherSymbol = 'x';
	}
}

int AIPlayer::play(Board &b, int &myScore, int &otherScore) {
	Cell *curCell;
	Cell *bestChoose;
	int curCellScore = -1 * b.getSize() * b.getSize();
	int bestCellScore = -1 * b.getSize() * b.getSize();

	while (!this->moves.empty()) {
		*curCell = this->moves.back();
		curCellScore = checkMove(b, myScore, otherScore, *curCell);
		if (curCellScore > bestCellScore) {
			bestCellScore = curCellScore;
			bestChoose = curCell;
		}
		this->moves.pop_back();
	}
}

int AIPlayer::checkMove(Board &b, int &myScore, int &otherScore, Cell cell) {
	vector<Cell> v;
	int myStart = myScore;
	int otherStart = otherScore;
	int worstCase = b.getSize() * b.getSize();
	int curScore = b.getSize() * b.getSize();

	this->makeMove(cell, myScore, otherScore, b);
	Board newBoard(b);
	this->generateMoves(b, v);

	while (!v.empty()) {
		curScore = curMoveScore(v.back(), myScore, otherScore, newBoard);
		if (curScore < worstCase) {
			worstCase = curScore;
		}
		myScore = myStart;
		otherScore = otherStart;
		v.pop_back();
	}
	return worstCase;
}

int AIPlayer::curMoveScore(Cell cell, int &myScore, int &otherScore, Board &b) {
	this->makeMove(cell, myScore, otherScore, b);
	return myScore - otherScore;
}
