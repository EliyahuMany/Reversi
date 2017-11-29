/*
 * AllTests.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#include "../Board.h"
#include "gtest/gtest.h"

using namespace std;

TEST (boardTest,startBoard) {
	Board b(4);
	EXPECT_EQ(b.getBoard()[2][2], 'o');
}
