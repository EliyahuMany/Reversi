/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#include "Game_Test.h"

/**
 * check if a this game end in draw 2:2.
 */
TEST_F(Game_Test, CheckDrawGame) {
    EXPECT_EQ(g->getOScore(), 2) << ("xScore dont initialized to 2");
    EXPECT_EQ(g->getXScore(), 2) << ("xScore dont initialized to 2");
    EXPECT_EQ(g->getXScore(), g->getOScore()) << ("scores don't initialized well");
}