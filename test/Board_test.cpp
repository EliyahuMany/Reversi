//
// Created by eliyahu on 11/29/17.
//

#include "Board_test.h"

TEST_F(Board_test, StartingBoard) {
        int center = bo->getSize() / 2;
        EXPECT_EQ(center , 4) << ("getSize() doesn't work well");
        char** board = bo->getBoard();
        EXPECT_TRUE(board != NULL) << ("getBoard() doesn't work well");
        for (int i = 0; i < bo->getSize(); i++) {
            for (int j = 0; j < bo->getSize(); j++) {
                EXPECT_TRUE(board[i][j] != NULL)
                                    << ("board isn't initialize well, there is blank cell");
            }
        }
        EXPECT_EQ(board[center][center] , 'o') << ("wrong char in this cell");
        EXPECT_EQ(board[center+1][center+1] , 'o') << ("wrong char in this cell");
        EXPECT_EQ(board[center+1][center] , 'x') << ("wrong char in this cell");
        EXPECT_EQ(board[center][center+1] , 'x') << ("wrong char in this cell");
}