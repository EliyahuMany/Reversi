//
// Created by orian on 11/30/17.
//

#ifndef RAVERSI_PLAYERS_TEST_H
#define RAVERSI_PLAYERS_TEST_H

#include <gtest/gtest.h>
#include "../include/Board.h"
#include "../include/Players.h"
#include "../include/Human.h"
#include "../include/Cell.h"
#include <vector>

class Players_Test : public testing::Test {
    virtual void SetUp() {
        pX = new Human('X');
    }

    virtual void TearDown() {
        delete pX;
    }

protected:
    Players *pX;

};

#endif //RAVERSI_PLAYERS_TEST_H
