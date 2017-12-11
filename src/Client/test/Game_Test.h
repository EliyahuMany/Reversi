/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_GAME_TEST_H
#define RAVERSI_GAME_TEST_H

#include <gtest/gtest.h>
#include "../include/Board.h"
#include "../include/Players.h"
#include "../include/Human.h"
#include "../include/GameFlow.h"
#include "../include/AIPlayer.h"
#include "../include/ConsolePrint.h"
#include <vector>

class Game_Test : public testing::Test {
    /**
     * test constructor.
     */
    virtual void SetUp() {
        this->p = new ConsolePrint();
        g = new GameFlow(2, 2, *p);
    }

    /**
     * test destructor.
     */
    virtual void TearDown() {
        delete g;
    }

protected:
    GameFlow *g;
    Print *p;
};


#endif //RAVERSI_GAME_TEST_H
