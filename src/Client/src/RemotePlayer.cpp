/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <cstdlib>
#include "../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(char symbol, Client &client, Print &printer) : Players(symbol, printer), client(client),
                                                                          cell(Cell()) {
}

Cell &RemotePlayer::play(Board &b, int &myScore, int &otherScore) {
    this->printer.string((char *) "Waiting for other player move..");
    string s;
    client.receiveMove(s);
    char *c = new char[s.size() + 1];
    strcpy(c, s.c_str());
    if (strcmp(c, "NoMove") == 0) {
        this->printer.string((char *) "No possible move");
        this->cell.emptyTrue();
    } else if (s == "exit") {
        cout << "dsad" << endl;
        this->printer.string((char *) "server is closed");
        exit(0);
    } else {
        this->cell.setCell(((int) c[0]) - 48, ((int) c[2]) - 48);
        this->printer.played(this->symbol, c);
        this->cell.emptyFalse();
    }
    delete[] c;
    return this->cell;
}