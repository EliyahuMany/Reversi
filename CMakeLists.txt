cmake_minimum_required(VERSION 3.8)
project(raversi)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES

        src/AIPlayer.cpp
        include/AIPlayer.h
        src/Board.cpp
        include/Board.h
        src/Cell.cpp
        include/Cell.h
        src/Game.cpp
        include/Game.h
        src/Human.cpp
        include/Human.h
        src/Players.cpp
        include/Players.h)

set(TEST_FILES
        test/AllTests.cpp
        src/AIPlayer.cpp
        include/AIPlayer.h
        src/Board.cpp
        include/Board.h
        src/Cell.cpp
        include/Cell.h
        src/Game.cpp
        include/Game.h
        src/Human.cpp
        include/Human.h
        src/Players.cpp
        include/Players.h test/Board_test.cpp test/Board_test.h test/Players_Test.cpp test/Players_Test.h test/Game_Test.cpp test/Game_Test.h)

add_executable(raversi ${SOURCE_FILES} main.cpp)
add_executable(raversiTest ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(raversiTest gtest gtest_main)