/*
 * AIPlayer.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#include "../include/AIPlayer.h"

AIPlayer::AIPlayer(char symbol) :
        Players(symbol) {
    this->symbol = symbol;
    if (this->symbol == 'X') {
        this->otherSymbol = 'O';
    } else {
        this->otherSymbol = 'X';
    }
}

int AIPlayer::play(Board &b, int &myScore, int &otherScore) {
    Cell *curCell;
    Cell *bestChoose;
    int curCellScore = -1 * b.getSize() * b.getSize();
    int bestCellScore = -1 * b.getSize() * b.getSize();
    Board bCopy(b.getSize());
    this->generateMoves(b, this->moves);
    if (!this->moves.empty()) {
        cout << "\nAI is playing..." << endl;
        while (!this->moves.empty()) {
            curCell = &this->moves.back();
            b.makeCopy(bCopy);
            curCellScore = checkMove(bCopy, myScore, otherScore,
                                     *curCell);
            if (curCellScore > bestCellScore) {
                bestCellScore = curCellScore;
                bestChoose = curCell;
            }
            this->moves.pop_back();
        }
        makeMove(*bestChoose, myScore, otherScore, b);
        return 1;
    } else {
        return 0;
    }
}

int AIPlayer::checkMove(Board &b, int &myScore, int &otherScore, Cell cell) {
    vector<Cell> v;
    int myStart = myScore;
    int otherStart = otherScore;
    int worstCase = b.getSize() * b.getSize();
    int curScore = b.getSize() * b.getSize();

    this->makeMove(cell, myStart, otherStart, b);
//	Board newBoard(b);
    this->changeSymbolForRival();
    this->generateMoves(b, v);

    myStart = myScore;
    otherStart = otherScore;

    while (!v.empty()) {
        curScore = curMoveScore(v.back(), myStart, otherStart, b);
        if (curScore < worstCase) {
            worstCase = curScore;
        }
        myStart = myScore;
        otherStart = otherScore;
        v.pop_back();
        b.print();
        cout << endl;
    }
    this->changeSymbolForRival();
    // delete board;
    return worstCase;
}

int AIPlayer::curMoveScore(Cell cell, int &myScore, int &otherScore, Board &b) {
    this->makeMove(cell, myScore, otherScore, b);
    return myScore - otherScore;
}

void AIPlayer::changeSymbolForRival() {
    char temp;
    temp = this->symbol;
    this->symbol = this->otherSymbol;
    this->otherSymbol = temp;
}