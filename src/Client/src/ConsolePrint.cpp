//
// Created by eliyahu on 12/10/17.
//

#include "../include/ConsolePrint.h"

ConsolePrint::ConsolePrint() : Print() {}

void ConsolePrint::string(char *string) {
    cout << string << endl;
}

void ConsolePrint::winner(char sign) {
    cout << sign << " is the winner!" << endl;
}

void ConsolePrint::connectionFailed(const char *m) {
    cout << "Connection failed: " << m << endl;
}

void ConsolePrint::played(char sign, char *cell) {
    cout << sign << " play " << "(" << cell << ")" << endl;
}

void ConsolePrint::playerTurn(char sign, vector<Cell> moves) {
    cout << sign << ": It's your move." << endl;
    cout << "Your possible moves:";
    for (unsigned int i = 0; i < moves.size(); ++i) {
        Cell c = moves[i];
        cout << "(" << c.getX() << "," << c.getY() << ")";
    }
    cout << endl;
}

void ConsolePrint::board(Board &board) {
    for (int i = 0; i <= board.getSize(); i++) {
        for (int j = 0; j <= board.getSize(); ++j) {
            if (i == 0 && j == 0) {
                if (board.getSize() >= 10) {
                    cout << "  ";
                } else {
                    cout << ' ';
                }
            } else if (i == 0) {
                cout << ' ';
                cout << j;
                if (j < 10) {
                    cout << ' ';
                }
            } else if (j == 0) {
                if (board.getSize() >= 10) {
                    if (i < 10) {
                        cout << i << ' ';
                    } else {
                        cout << i;
                    }
                } else {
                    cout << i;
                }
            } else if (board.getBoard()[i][j] != ' ') {
                cout << ' ';
                cout << board.getBoard()[i][j];
                cout << ' ';
            } else {
                cout << "   ";
            }
            cout << "|";
        }
        cout << endl;
        if (board.getSize() >= 10) {
            cout << "---";
        } else {
            cout << "--";
        }
        for (int k = 0; k < board.getSize(); ++k) {
            cout << "----";
        }
        cout << endl;
    }
}