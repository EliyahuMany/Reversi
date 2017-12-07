/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "../include/GameFlow.h"

Game::Game(int size, int choose) : pX(new Human('X')), gameL(GameLogic(size)) {
    if (choose == 1)
        this->pO = new Human('O');
    else
        this->pO = new AIPlayer('O', gameL);
    this->xScore = 2;
    this->oScore = 2;
}

void Game::run() {
    int flagX = 1, flagO = 1; //mark if X/O can play.
    this->gameL.getGameBoard().print();
    while (flagX != 0 || flagO != 0) {
        this->gameL.generateMoves(this->pX, this->pX->getMoves(), this->gameL.getGameBoard());
        if (this->pX->getMoves().empty()) {
            flagX = 0;
        } else {
            this->gameL.makeMove(pX->play(this->gameL.getGameBoard(), this->xScore, this->oScore), this->xScore,
                                 this->oScore, this->pX,
                                 this->gameL.getGameBoard());
            this->gameL.getGameBoard().print();
        }
        this->gameL.generateMoves(this->pO, this->pO->getMoves(), this->gameL.getGameBoard());
        if (this->pO->getMoves().empty()) {
            flagO = 0;
        } else {
            this->gameL.makeMove(pO->play(this->gameL.getGameBoard(), this->oScore, this->xScore), this->oScore,
                                 this->xScore, this->pO,
                                 this->gameL.getGameBoard());
            this->gameL.getGameBoard().print();
        }
    }

    if (xScore > oScore) {
        cout << "X is the winner!" << endl;
    } else if (xScore < oScore) {
        cout << "O is the winner!" << endl;
    } else {
        cout << "Draw" << endl;
    }
    this->gameL.deleteBoard();
}

int Game::getXScore() const {
    return this->xScore;
}

int Game::getOScore() const {
    return this->oScore;
}

Game::~Game() {
    delete pX;
    delete pO;
}
