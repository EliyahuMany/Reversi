/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <iostream>
#include "include/Print.h"
#include "include/GameFlow.h"
#include "include/ConsolePrint.h"

using namespace std;

/*
 * This is the main function.
 * create the game and run it.
 */

int main() {
    int size, choose;
    ConsolePrint printer;

    while (true) {
        printer.string((char *) "Choose an option from the menu:");
        printer.string((char *) "1. Human vs Human");
        printer.string((char *) "2. Human vs AI");
        printer.string((char *) "3. Human vs Wireless Player");
        cin >> choose;
        if (choose == 1 || choose == 2 || choose == 3)
            break;
        printer.string((char *) "Wrong input!");
        cin.clear();
        cin.ignore(100, '\n');
    }
    size = 8;
    GameFlow game = GameFlow(size, choose, printer);
    game.run();
    return 0;
}
