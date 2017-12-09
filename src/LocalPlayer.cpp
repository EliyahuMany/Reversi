//
// Created by orian on 12/9/17.
//

#include "../include/LocalPlayer.h"

LocalPlayer::LocalPlayer(char symbol, Client &client) : Players(symbol), client(client), c(Cell()) {
}

Cell &LocalPlayer::play(Board &b, int &myScore, int &otherScore) {
    if (this->moves.empty()) {
        this->client.sendMove("NoMove");
        return this->c;
    } else {
        char choose[20];
        cout << this->symbol << ": It's your move." << endl;
        cout << "Your possible moves:";
        for (unsigned int i = 0; i < this->moves.size(); ++i) {
            Cell c = this->moves[i];
            cout << "(" << c.getX() << "," << c.getY() << ")";
        }
        cout << endl;
        while (true) {
            cout << "Please enter your move row,col: " << endl;
            cin >> choose;
            for (int i = 0; i < this->moves.size(); ++i) {
                if ((int) choose[0] - 48 == this->moves[i].getX()
                    && (int) choose[2] - 48 == this->moves[i].getY()) {
                    while (!this->moves.empty()) {
                        this->moves.pop_back();
                    }
                    client.sendMove(choose);
                    return this->moves[i];
                }
            }
            cout << "Wrong entry!" << endl;
        }
    }
}