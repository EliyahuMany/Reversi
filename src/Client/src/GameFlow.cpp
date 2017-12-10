/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "../include/GameFlow.h"
#include "../include/Client.h"
#include "../include/RemotePlayer.h"
#include "../include/LocalPlayer.h"

GameFlow::GameFlow(int size, int choose) : gameL(GameLogic(size)) {
    //online game:
    if (choose == 3) {
        Client client("127.0.0.1", 8443);
        int playerNum = client.connectToServer();
        if (playerNum == 1) {
            this->pX = new LocalPlayer('X', client);
            this->pO = new RemotePlayer('O', client);
        } else if (playerNum == 2) {
            this->pX = new RemotePlayer('X', client);
            this->pO = new LocalPlayer('O', client);
        }
    }//offline game:
    else {
        this->pX = new Human('X');
        if (choose == 1)
            this->pO = new Human('O');
        else
            this->pO = new AIPlayer('O', gameL);
    }
    this->xScore = 2;
    this->oScore = 2;
}

void GameFlow::run() {
    int flagX = 1, flagO = 1; //mark if X/O can play.
    this->gameL.getGameBoard().print();
    while (flagX != 0 || flagO != 0) {
        this->gameL.generateMoves(this->pX, this->pX->getMoves(), this->gameL.getGameBoard());
        flagX = this->gameL.makeMove(pX->play(this->gameL.getGameBoard(), this->xScore, this->oScore), this->xScore,
                                     this->oScore, this->pX,
                                     this->gameL.getGameBoard());
        this->gameL.getGameBoard().print();
        this->gameL.generateMoves(this->pO, this->pO->getMoves(), this->gameL.getGameBoard());
        flagO = this->gameL.makeMove(pO->play(this->gameL.getGameBoard(), this->oScore, this->xScore), this->oScore,
                                     this->xScore, this->pO,
                                     this->gameL.getGameBoard());
        this->gameL.getGameBoard().print();
    }

    if (xScore > oScore) {
        cout << "X is the winner!" <<
             endl;
    } else if (xScore < oScore) {
        cout << "O is the winner!" <<
             endl;
    } else {
        cout << "Draw" <<
             endl;
    }
    this->gameL.

            deleteBoard();

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
