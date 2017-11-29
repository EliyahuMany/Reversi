/*
 * main.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: orian edri
 *      ID:308335454
 */

#include <iostream>
#include "Game.h"
using namespace std;

int main() {
	cout << "Choose a board size:" << endl;
	cout << "1. 6X6" << endl;
	cout << "2. 8X8" << endl;
	cout << "3. 10X10" << endl;
	int choose, size = 0;
	while (size == 0) {
		cin >> choose;
		if (choose == 1)
			size = 7;
		else if (choose == 2)
			size = 9;
		else if (choose == 3)
			size = 11;
		else
			cout << "Wrong input. Please choose again!" << endl;
	}
	Game g(5);
	g.run();
}

