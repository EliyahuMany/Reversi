/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_BOARD_TEST_H
#define RAVERSI_BOARD_TEST_H


#include <gtest/gtest.h>
#include "../include/Board.h"

class Board_test : public testing::Test {
    /**
     * test constructor.
     */
    virtual void SetUp() {
        b = new Board(8);
    }

    /**
     * test destructor.
     */
    virtual void TearDown() {
        delete b;
    }

protected:
    Board *b;

};


#endif //RAVERSI_BOARD_TEST_H
