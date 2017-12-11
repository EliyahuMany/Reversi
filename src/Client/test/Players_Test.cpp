/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "Players_Test.h"
/**
 * generate a vector of a player acording to some board.
 */
TEST_F(Players_Test, MovesVector) {
    vector<Cell> moves;
    this->g->generateMoves(this->pX, moves, this->g->getGameBoard());
    EXPECT_TRUE(!moves.empty()) << ("couldn't generate moves");
}

/**
 * make if the changeSymbol.. function change the symbol for calculate the rival best moves.
 */
TEST_F(Players_Test, ChangeSymbol) {
    char s = this->pO->getSymbol();
    this->pO->changeSymbolForRival();
    EXPECT_TRUE(this->pO->getSymbol() != s) << ("symbol doesnt changed");
}