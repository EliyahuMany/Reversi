/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "../include/Game.h"

Game::Game(int size, int choose) :
        b(Board(size)), pX(new Human('X')) {
    if (choose == 1)
        this->pO = new Human('O');
    else
        this->pO = new AIPlayer('O');
}

void Game::run() {
    int xScore = 2, oScore = 2;
    int flagX = 1, flagO = 1; //mark if X/O can play.
    this->b.print();
    while (flagX != 0 || flagO != 0) {
        flagX = pX->play(this->b, xScore, oScore);
        if (flagX) {
            this->b.print();
        }
        flagO = pO->play(this->b, oScore, xScore);
        if (flagO) {
            this->b.print();
        }
    }
    if (xScore > oScore)
        cout << "X is the winner!" << endl;
    else if (xScore < oScore)
        cout << "O is the winner!" << endl;
    else
        cout << "Draw" << endl;
}

Game::~Game() {
    delete pX;
    delete pO;
}
