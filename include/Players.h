/*
 * Players.h
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_

#include "Cell.h"
#include "Board.h"
#include <vector>

class Players {
public:
	Players(char symbol);
	void generateMoves(Board &b,vector<Cell> &vec);
	void makeMove(Cell cell, int &myScore, int &otherScore, Board &b);
	void changeCells(vector<Cell> cellsToChange, int &myScore, int &otherScore,
			Board &b);
	virtual int play(Board &b, int &myScore, int &otherScore)=0;
protected:
	vector<Cell> moves;
	char symbol;
};

#endif /* PLAYERS_H_ */
