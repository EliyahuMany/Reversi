//
// Created by eliyahu on 11/29/17.
//

#ifndef RAVERSI_BOARD_TEST_H
#define RAVERSI_BOARD_TEST_H


#include <gtest/gtest.h>
#include "../include/Board.h"

class Board_test : public testing::Test {
    virtual void SetUp() {
        b = new Board(8);
    }
    virtual void TearDown() {
        delete b;
    }

protected:
    Board* b;

};


#endif //RAVERSI_BOARD_TEST_H
