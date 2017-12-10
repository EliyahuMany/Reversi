//
// Created by eliyahu on 12/10/17.
//

#include "../include/ConsolePrint.h"

ConsolePrint::ConsolePrint(Board board) : Print(board) {}

void ConsolePrint::winner(char sign) {
    cout << sign << " is the winner!" << endl;
}

void ConsolePrint::draw() {
    cout << "Draw!" << endl;
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

void ConsolePrint::enterMoves() {
    cout << "Please enter your move row,col: " << endl;
}

void ConsolePrint::aiTurn() {
    cout << "\nAI is playing..." << endl;
}

void ConsolePrint::board() {
    for (int i = 0; i <= this->gameBoard.getSize(); i++) {
        for (int j = 0; j <= this->gameBoard.getSize(); ++j) {
            if (i == 0 && j == 0) {
                if (this->gameBoard.getSize() >= 10) {
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
                if (this->gameBoard.getSize() >= 10) {
                    if (i < 10) {
                        cout << i << ' ';
                    } else {
                        cout << i;
                    }
                } else {
                    cout << i;
                }
            } else if (this->gameBoard.getBoard()[i][j] != ' ') {
                cout << ' ';
                cout << this->gameBoard.getBoard()[i][j];
                cout << ' ';
            } else {
                cout << "   ";
            }
            cout << "|";
        }
        cout << endl;
        if (this->gameBoard.getSize() >= 10) {
            cout << "---";
        } else {
            cout << "--";
        }
        for (int k = 0; k < this->gameBoard.getSize(); ++k) {
            cout << "----";
        }
        cout << endl;
    }
}