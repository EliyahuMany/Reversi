/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/Cell.h"

Cell::Cell(int x, int y) {
    this->x = x;
    this->y = y;
    this->isEmptyCell = false;
}

Cell::Cell() {
    this->isEmptyCell = true;
}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

bool Cell::isEmpty() {
    return this->isEmptyCell;
}

void Cell::setCell(int x, int y) {
    this->x = x;
    this->y = y;
}

void Cell::emptyTrue() {
    this->isEmptyCell = true;
}

void Cell::emptyFalse() {
    this->isEmptyCell = false;
}