/*
 * Player.h
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#ifndef HUMAN_H_
#define HUMAN_H_
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Board.h"
using namespace std;

class Player {
public:
	/**
	 * Constructor - create a player.
	 */
	Player(char symbol);
	/**
	 * search for the available moves of the player and add them to possible move vector.
	 */
	void generateMoves(Board &b);
	/**
	 * play one turn of this player.
	 */
	void play(Board &b, int &myScore, int &otherScore);
	/**
	 * change the relevant cells to this player move.
	 */
	void flipCells(Board &b, Cell chosenCell, int &myScore, int &otherScore);
	/**
	 * return the possible moves vector of this player.
	 */
	const vector<Cell>& getPossibleMoves() const {
		return possibleMoves;
	}
private:
	char symbol, otherSymbol;
	vector<Cell> possibleMoves;
};

#endif /* HUMAN_H_ */
