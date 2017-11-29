/*
 * Cell.h
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#ifndef CELL_H_
#define CELL_H_
#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

class Cell {
public:
	/**
	 * Constructor - make a Cell (x,y) coordinates.
	 */
	Cell(int x, int y);
	/**
	 * return x value of this cell.
	 */
	int getX();
	/**
	 * return y value of this cell.
	 */
	int getY();
	/**
	 * check if this cell is available to a move and return true, else otherwise.
	 * if this cell is available this function put all the cell that need to convert their symbol in a vector.
	 */
	bool checkIfAvailable(Board &b, Cell nextC, char player);
	/**
	 * return the vector of the cellד that need to change the symbol.
	 */
	vector<Cell>& getCandidateForFlip();
private:
	int x, y;
	vector<Cell> candidateForFlip;
};

#endif /* CELL_H_ */
