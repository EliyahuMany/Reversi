/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "Board_test.h"

/**
 * check if the board initialize well. if the getters work.
 */
TEST_F(Board_test, StartingBoard) {
        int center = b->getSize() / 2;
        EXPECT_EQ(center , 4) << ("getSize() doesn't work well");
        char** board = b->getBoard();
        EXPECT_TRUE(board != NULL) << ("getBoard() doesn't work well");
        for (int i = 0; i < b->getSize(); i++) {
            for (int j = 0; j < b->getSize(); j++) {
                EXPECT_TRUE(board[i][j] != NULL)
                                    << ("board isn't initialize well, there is blank cell");
            }
        }
        EXPECT_EQ(board[center][center] , 'O') << ("wrong char in this cell");
        EXPECT_EQ(board[center+1][center+1] , 'O') << ("wrong char in this cell");
        EXPECT_EQ(board[center+1][center] , 'X') << ("wrong char in this cell");
        EXPECT_EQ(board[center][center+1] , 'X') << ("wrong char in this cell");
}

/**
 * make a copy of a board and check if they equla.
 */
TEST_F(Board_test,CopyBoard){
    Board copyB(this->b->getSize());
    this->b->getBoard()[3][3]='X';
    this->b->getBoard()[6][2]='X';
    this->b->getBoard()[1][7]='X';
    this->b->makeCopy(copyB);
    for (int i = 0; i < b->getSize(); i++) {
        for (int j = 0; j < b->getSize(); j++) {
            EXPECT_EQ(this->b->getBoard()[i][j] ,copyB.getBoard()[i][j])
                                << ("board copy error");
        }
    }
}