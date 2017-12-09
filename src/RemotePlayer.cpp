//
// Created by orian on 12/9/17.
//

#include "../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(char symbol, Client &client) : Players(symbol), client(client), cell(Cell()) {
}

Cell &RemotePlayer::play(Board &b, int &myScore, int &otherScore) {
    char c[20];
    client.receiveMove(c);
    if (strcmp(c, "NoMove") == 0) {
        this->cell.emptyTrue();
    } else {
        this->cell.setCell(((int) c[0]) - 48, ((int) c[2]) - 48);
        this->cell.emptyFalse();
        return this->cell;
    }
}