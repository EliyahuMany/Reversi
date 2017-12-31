/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <unistd.h>
#include "../include/Command.h"

Command::Command(vector<GameInfo> &gamesList) : gamesList(gamesList) {}

void Command::commandNotify(int clientSocket, string msg) {
    int n = write(clientSocket, msg.c_str(), msg.length());
    if (n == -1) {
        throw "Error int writing to client";
    }
}