/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_PLAYERS_TEST_H
#define RAVERSI_PLAYERS_TEST_H

#include <gtest/gtest.h>
#include "../include/Board.h"
#include "../include/Players.h"
#include "../include/Human.h"
#include "../include/Cell.h"
#include "../include/AIPlayer.h"
#include "../include/ConsolePrint.h"
#include <vector>

class Players_Test : public testing::Test {
    /**
     * test constructor.
     */
    virtual void SetUp() {
        this->p = new ConsolePrint();
        g = new GameLogic(8);
        pX = new Human('X', *p);
        pO = new AIPlayer('O', *g, *p);
    }

    virtual void TearDown() {
        delete pX;
        delete pO;
        delete g;
    }

protected:
    Players *pX;
    AIPlayer *pO;
    Print *p;
    GameLogic *g;
};

#endif //RAVERSI_PLAYERS_TEST_H
