/*
 * Player.h
 *
 *  Created on: Nov 10, 2017
 *      Author: orian edri
 *      ID: 308335454
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Board.h"
#include "Players.h"

using namespace std;

class Human : public Players {
public:
    /**
     * Constructor - create a player.
     */
    Human(char symbol);

    /**
     * search for the available moves of the player and add them to possible move vector.
     */
    int play(Board &b, int &myScore, int &otherScore);
    /**
     * change the relevant cells to this player move.
     */
};

#endif /* HUMAN_H_ */
