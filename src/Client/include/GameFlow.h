/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
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
    GameFlow(Players *pX, Players *pO, GameLogic gameLogic, Print &printer);

    /**
     * run the game until the players can't make a move.
     */
    void run();


    /**
    * Destractuor - delete the game.
    */
    virtual ~GameFlow();

    /**
    * @return the score of player X.
    */
    int getXScore() const;

    /**
     * @return the score of player O.
     */
    int getOScore() const;

private:
    GameLogic gameL;
    Players *pX;
    Players *pO;
    int xScore, oScore;
    bool oIsRemote;
    Print &printer;
};

#endif /* GAME_H_ */
