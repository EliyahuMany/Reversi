/*
 * AllTests.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: eliyahu
 */

#include "../include/Board.h"
#include "gtest/gtest.h"

using namespace std;

GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}


