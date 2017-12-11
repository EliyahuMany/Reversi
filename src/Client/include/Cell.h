/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
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


    /**
    * return the boolean isEmptyCell.
    */
    bool isEmpty();

    /**
     * setter
     * @param x the row .
     * @param y the column.
     */
    void setCell(int x, int y);

    /**
     * set the empty boolean as true.
     */
    void emptyTrue();

    /**
    * set the empty boolean as false.
    */
    void emptyFalse();

private:
    int x, y;
    vector<Cell> candidateForFlip;
    bool isEmptyCell;
};

#endif /* CELL_H_ */
