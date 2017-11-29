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
	int size;

	while (true) {
		cout << "Please choose board size (even, bigger than 2):" << endl;
		cin >> size;
		if (size >= 4 && size % 2 == 0) {
			break;
		} else {
			cout << "Wrong entry!" << endl;
		}
	}
	Game game = Game(size);
	game.run();
	return 0;
}
