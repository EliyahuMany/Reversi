/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <fstream>
#include <cstdlib>
#include "../include/GameFlow.h"
#include "../include/Client.h"
#include "../include/RemotePlayer.h"
#include "../include/LocalPlayer.h"

GameFlow::GameFlow(int size, int choose, Print &printer) : gameL(GameLogic(size)), printer(printer) {
    //online game:
    if (choose == 3) {

    }//offline game:
    else {
        this->pX = new Human('X', printer);
        if (choose == 1)
            this->pO = new Human('O', printer);
        else
            this->pO = new AIPlayer('O', gameL, printer);
    }
    this->xScore = 2;
    this->oScore = 2;
}

void GameFlow::run() {
    int flagX = 1, flagO = 1; //mark if X/O can play.
    this->printer.board(this->gameL.getGameBoard());
    while ((flagX != 0 || flagO != 0) && ((this->xScore + this->oScore) < (this->gameL.getGameBoard().getSize() *
                                                                           this->gameL.getGameBoard().getSize()))) {
        this->gameL.generateMoves(this->pX, this->pX->getMoves(), this->gameL.getGameBoard());
        flagX = this->gameL.makeMove(pX->play(this->gameL.getGameBoard(), this->xScore, this->oScore), this->xScore,
                                     this->oScore, this->pX,
                                     this->gameL.getGameBoard());
        if (flagX == 1)
            this->printer.board(this->gameL.getGameBoard());
        this->gameL.generateMoves(this->pO, this->pO->getMoves(), this->gameL.getGameBoard());
        flagO = this->gameL.makeMove(pO->play(this->gameL.getGameBoard(), this->oScore, this->xScore), this->oScore,
                                     this->xScore, this->pO,
                                     this->gameL.getGameBoard());
        if (flagO == 1)
            this->printer.board(this->gameL.getGameBoard());
    }

    if (xScore > oScore) {
        this->printer.string((char *) "X is the winner!");
    } else if (xScore < oScore) {
        this->printer.string((char *) "O is the winner!");
    } else {
        this->printer.string((char *) "Draw!");
    }
    this->gameL.deleteBoard();

}

int GameFlow::getXScore() const {
    return this->xScore;
}

int GameFlow::getOScore() const {
    return this->oScore;
}

GameFlow::~GameFlow() {
    delete pX;
    delete pO;
}
