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

    Cell();

    /**
     * return x value of this cell.
     */
    int getX();

    /**
     * return y value of this cell.
     */
    int getY();

    bool isEmpty();

    void setCell(int x, int y);

    void emptyTrue();

    void emptyFalse();

private:
    int x, y;
    vector<Cell> candidateForFlip;
    bool isEmptyCell;
};

#endif /* CELL_H_ */
