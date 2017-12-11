/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: orian Edri
 *      ID: 308335454
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <string.h>
using namespace std;

class Board {
public:
	/**
	 * Constructor - make the starting board.
	 */
	Board(int);

	void makeCopy(Board &bCopy);
	/**
	 * Destructor - delete the board(**).
	 */
	~Board();
	/**
	 * return the board array.
	 */
	char** getBoard();
	/**
	 * return the size of the board.
	 */
	int getSize();

private:
	char** board;
	int size;
};

#endif /* BOARD_H_ */
