/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
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
        ifstream cFile;
        cFile.open("../../../exe/client_config.txt");
        string ip, port;
        if (cFile.is_open()) {
            getline(cFile, ip);
            getline(cFile, port);
        } else
            exit(1);
        cFile.close();
        Client client(ip.c_str(), atoi(port.c_str()), this->printer);
        try {
            int playerNum = client.connectToServer();
            if (playerNum == 1) {
                this->pX = new LocalPlayer('X', client, printer);
                this->pO = new RemotePlayer('O', client, printer);
            } else if (playerNum == 2) {
                this->pX = new RemotePlayer('X', client, printer);
                this->pO = new LocalPlayer('O', client, printer);
            }
        } catch (const char *m) {
            this->printer.connectionFailed(m);
            exit(1);
        }
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
    while (flagX != 0 || flagO != 0) {
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
