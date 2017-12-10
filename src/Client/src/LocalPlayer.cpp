//
// Created by orian on 12/9/17.
//

#include "../include/LocalPlayer.h"

LocalPlayer::LocalPlayer(char symbol, Client &client) : Players(symbol), client(client), cell(Cell()) {
}

Cell &LocalPlayer::play(Board &b, int &myScore, int &otherScore) {
    if (this->moves.empty()) {
        string s = "NoMove";
        char *c = new char[s.length() + 1];
        strcpy(c, s.c_str());
        this->client.sendMove(c);
        delete[] c;
        return this->cell;
    } else {
        string choose;
        cout << this->symbol << ": It's your move." << endl;
        cout << "Your possible moves:";
        for (unsigned int i = 0; i < this->moves.size(); ++i) {
            Cell cell = this->moves[i];
            cout << "(" << cell.getX() << "," << cell.getY() << ")";
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
                    char *c = new char[choose.length() + 1];
                    strcpy(c, choose.c_str());
                    client.sendMove(c);
                    delete[] c;
                    return this->moves[i];
                }
            }
            cout << "Wrong entry!" << endl;
        }
    }
}