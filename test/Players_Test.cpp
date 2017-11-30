//
// Created by orian on 11/30/17.
//

#include "Players_Test.h"

TEST_F(Players_Test, MovesVector) {
    Board b(8);
    vector<Cell> moves;
    this->pX->generateMoves(b, moves);
    EXPECT_TRUE(!moves.empty()) << ("couldn't generate moves");
}