//
// Created by eliyahu on 12/7/17.
//

#include "../include/GameLogic.h"

GameLogic::GameLogic(int size) : board(new Board(size)) {}

void GameLogic::generateMoves(Players *player, vector<Cell> &vec, Board &b) {
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
                               != player->getSymbol()) {
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
                                           && b.getBoard()[i + (k * temp)][j + (l * temp)] == player->getSymbol()) {
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

int GameLogic::makeMove(Cell cell, int &myScore, int &otherScore, Players *player, Board &b) {
    int temp;
    vector<Cell> v;

    if (cell.isEmpty()) {
        return 0;
    }
    for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
            temp = 1;
            if ((cell.getX() + (k * temp)) <= b.getSize()
                && (cell.getY() + (l * temp)) <= b.getSize()
                && b.getBoard()[cell.getX() + (k * temp)][cell.getY()
                                                          + (l * temp)] != ' '
                && b.getBoard()[cell.getX() + (k * temp)][cell.getY()
                                                          + (l * temp)] != player->getSymbol() && (l != 0 || k != 0)) {
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
                                                                         + (l * temp)] == player->getSymbol()) {
                        while (temp > 1) {
                            temp--;
                            v.push_back(Cell(cell.getX() + (k * temp), cell.getY() + (l * temp)));
                        }
                        break;
                    }
                }
            }
        }
    }
    myScore++;
    changeCells(v, myScore, otherScore, player, b);
    b.getBoard()[cell.getX()][cell.getY()] = player->getSymbol();
    return 1;
}

void GameLogic::changeCells(vector<Cell> cellsToChange, int &myScore, int &otherScore, Players *player,
                            Board &b) {
    while (!cellsToChange.empty()) {
        b.getBoard()[cellsToChange.back().getX()][cellsToChange.back().getY()] =
                player->getSymbol();
        myScore++;
        otherScore--;
        cellsToChange.pop_back();
    }
}

Board &GameLogic::getGameBoard() {
    return *this->board;
}

void GameLogic::deleteBoard() {
    delete board;
}