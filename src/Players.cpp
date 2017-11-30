/*
 * Players.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#include "../include/Players.h"

Players::Players(char symbol) :
        symbol(symbol) {
}

void Players::generateMoves(Board &b, vector<Cell> &vec) {
    int temp;
    bool found;

    for (int i = 1; i <= b.getSize(); ++i) {
        for (int j = 1; j <= b.getSize(); j++) {
            if (b.getBoard()[i][j] == ' ') {
                found = false;
                for (int k = -1; k <= 1; ++k) {
                    for (int l = -1; l <= 1; ++l) {
                        temp = 1; //raised for each second player symbol in a row(col/cross).
                        if ((i + (k * temp)) <= b.getSize()
                            && (j + (l * temp)) <= b.getSize()
                            && (i + (k * temp)) > 0 && (j + (l * temp)) > 0
                            && b.getBoard()[i + (k * temp)][j + (l * temp)]
                               != ' '
                            && b.getBoard()[i + (k * temp)][j + (l * temp)]
                               != symbol) {
                            while (true) {
                                ++temp;
                                if ((i + (k * temp)) > b.getSize()
                                    || (i + (k * temp)) < 0
                                    || (j + (l * temp)) > b.getSize()
                                    || (j + (l * temp)) < 0
                                    || b.getBoard()[i + (k * temp)][j
                                                                    + (l * temp)] == ' ') {
                                    break;
                                } else if ((i + (k * temp)) <= b.getSize()
                                           && (i + (k * temp)) > 0
                                           && (j + (l * temp)) <= b.getSize()
                                           && (j + (l * temp)) > 0
                                           && b.getBoard()[i + (k * temp)][j
                                                                           + (l * temp)] == symbol) {
                                    vec.push_back(Cell(i, j));
                                    found = true;
                                    break;
                                }
                            }
                        }
                        if (found)
                            break;
                    } //4th for
                    if (found)
                        break;
                } //3rd for
            }
        } //2nd for
    } //1st for
}

void Players::makeMove(Cell cell, int &myScore, int &otherScore, Board &b) {
    int temp;
    vector<Cell> v;

    for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
            temp = 1;
            if ((cell.getX() + (k * temp)) <= b.getSize()
                && (cell.getY() + (l * temp)) <= b.getSize()
                && b.getBoard()[cell.getX() + (k * temp)][cell.getY()
                                                          + (l * temp)] != ' '
                && b.getBoard()[cell.getX() + (k * temp)][cell.getY()
                                                          + (l * temp)] != symbol && (l != 0 || k != 0)) {
                while (true) {
                    temp++;
                    if ((cell.getX() + (k * temp)) > b.getSize()
                        || (cell.getY() + (l * temp)) > b.getSize()
                        || b.getBoard()[cell.getX() + (k * temp)][cell.getY()
                                                                  + (l * temp)] == ' ') {
                        break;
                    } else if ((cell.getX() + (k * temp)) <= b.getSize()
                               && (cell.getY() + (l * temp)) <= b.getSize()
                               && b.getBoard()[cell.getX() + (k * temp)][cell.getY()
                                                                         + (l * temp)] == symbol) {
                        while (temp > 1) {
                            temp--;
                            v.push_back(
                                    Cell(cell.getX() + (k * temp),
                                         cell.getY() + (l * temp)));
                        }
                        break;
                    }
                }
            }
        }
    }
    myScore++;
    changeCells(v, myScore, otherScore, b);
    b.getBoard()[cell.getX()][cell.getY()] = symbol;
}

void Players::changeCells(vector<Cell> cellsToChange, int &myScore,
                          int &otherScore, Board &b) {
    while (!cellsToChange.empty()) {
        b.getBoard()[cellsToChange.back().getX()][cellsToChange.back().getY()] =
                symbol;
        myScore++;
        otherScore--;
        cellsToChange.pop_back();
    }
}
