/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include "Board.h"
#include "Human.h"
#include "AIPlayer.h"
#include "GameLogic.h"

using namespace std;

class GameFlow {
public:
    /**
     * Constructor - create a game session.
     */
    GameFlow(int size, int choose);

    /**
     * run the game until the players can't make a move.
     */
    void run();


    /**
    * Destractuor - delete the game.
    */
    virtual ~GameFlow();

    int getXScore() const;

    int getOScore() const;

private:
    GameLogic gameL;
    Players *pX;
    Players *pO;
    int xScore, oScore;
    bool oIsRemote;
};

#endif /* GAME_H_ */
