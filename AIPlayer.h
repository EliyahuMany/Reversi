/*
 * AIPlayer.h
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Board.h"
#include "Cell.h"
#include "Players.h"

class AIPlayer: public Players {
public:
	AIPlayer(char symbol);
	int play(Board &b, int &myScore, int &otherScore);
	int checkMove(Board& b, int &myScore, int &otherScore, Cell curCell);
	int curMoveScore(Cell cell, int &myScore, int &otherScore, Board &b);
	void rivalMoves(Board &b, vector<Cell> &vec);
private:
	char symbol, otherSymbol;
};

#endif /* AIPLAYER_H_ */
