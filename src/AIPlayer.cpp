/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "../include/AIPlayer.h"

AIPlayer::AIPlayer(char symbol, GameLogic gl) :
        Players(symbol), gl(gl) {
    this->symbol = symbol;
    if (this->symbol == 'X') {
        this->otherSymbol = 'O';
    } else {
        this->otherSymbol = 'X';
    }
}

Cell &AIPlayer::play(Board &b, int &myScore, int &otherScore) {
    Cell *curCell;
    Cell *bestChoose;
    int curCellScore = -1 * b.getSize() * b.getSize();
    int bestCellScore = -1 * b.getSize() * b.getSize();
    Board bCopy(b.getSize());
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
    return *bestChoose;
}

int AIPlayer::checkMove(Board &b, int &myScore, int &otherScore, Cell cell) {
    vector<Cell> v;
    int myStart = myScore;
    int otherStart = otherScore;
    int worstCase = b.getSize() * b.getSize();
    int curScore = b.getSize() * b.getSize();

    this->gl.makeMove(cell, myStart, otherStart, this, b);
    Board newBoard(b.getSize());
    this->changeSymbolForRival();
    this->gl.generateMoves(this, v, b);

    myStart = myScore;
    otherStart = otherScore;

    while (!v.empty()) {
        b.makeCopy(newBoard);
        curScore = curMoveScore(v.back(), myStart, otherStart, newBoard);
        if (curScore < worstCase) {
            worstCase = curScore;
        }
        myStart = myScore;
        otherStart = otherScore;
        v.pop_back();
    }
    this->changeSymbolForRival();
    // delete board;
    return worstCase;
}

int AIPlayer::curMoveScore(Cell cell, int &myScore, int &otherScore, Board &b) {
    this->gl.makeMove(cell, myScore, otherScore, this, b);
    return myScore - otherScore;
}

void AIPlayer::changeSymbolForRival() {
    char temp;
    temp = this->symbol;
    this->symbol = this->otherSymbol;
    this->otherSymbol = temp;
}