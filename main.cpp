/*
 * Eliyahu Many
 * id: 308249150
 */

#include <iostream>
#include "include/Board.h"
#include "include/Game.h"

using namespace std;

/*
 * This is the main function.
 * create the game and run it.
 */

int main() {
    int size, choose;

    while (true) {
        cout << "Choose an option from the menu:" << endl;
        cout << "1. Human vs Human" << endl;
        cout << "2. Human vs AI" << endl;
        cin >> choose;
        if (choose == 1 || choose == 2)
            break;
        cout << "Wrong input!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    while (true) {
        cout << "Please choose board size (even, bigger than 2):" << endl;
        cin >> size;
        if (size >= 4 && size % 2 == 0) {
            break;
        } else {
            cout << "Wrong entry!" << endl;
        }
        cin.clear();
        cin.ignore(100, '\n');
    }
    Game game = Game(size, choose);
    game.run();
    return 0;
}
