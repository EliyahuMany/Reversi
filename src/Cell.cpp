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
