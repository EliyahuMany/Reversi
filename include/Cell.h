/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
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

private:
	int x, y;
	vector<Cell> candidateForFlip;
};

#endif /* CELL_H_ */
