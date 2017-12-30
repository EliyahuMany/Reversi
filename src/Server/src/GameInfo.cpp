/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/GameInfo.h"

GameInfo::GameInfo(string name, int clientSocket1) : gameName(name), clientSocket1(clientSocket1) {}

const string &GameInfo::getName() const {
    return this->gameName;
}

int GameInfo::getClientSocket1() const {
    return clientSocket1;
}

int GameInfo::getClientSocket2() const {
    return clientSocket2;
}

void GameInfo::setClientSocket2(int clientSocket2) {
    GameInfo::clientSocket2 = clientSocket2;
}