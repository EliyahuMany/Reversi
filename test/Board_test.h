//
// Created by eliyahu on 11/29/17.
//

#ifndef RAVERSI_BOARD_TEST_H
#define RAVERSI_BOARD_TEST_H


#include <gtest/gtest.h>
#include "../include/Board.h"

class Board_test : public testing::Test {
    virtual void SetUp() {
        bo = new Board(8);
    }
    virtual void TearDown() {
        delete bo;
    }

protected:
    Board* bo;

};


#endif //RAVERSI_BOARD_TEST_H
