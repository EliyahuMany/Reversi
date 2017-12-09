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
#include <vector>

class Players_Test : public testing::Test {
    /**
     * test constructor.
     */
    virtual void SetUp() {
        pX = new Human('X');
        pO = new AIPlayer('O');
    }

    virtual void TearDown() {
        delete pX;
        delete pO;
    }

protected:
    Players *pX;
    AIPlayer *pO;

};

#endif //RAVERSI_PLAYERS_TEST_H
