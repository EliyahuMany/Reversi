//
// Created by orian on 1/2/18.
//

#include "../include/ServerGames.h"

ServerGames *ServerGames::instance = 0;
pthread_mutex_t ServerGames::lock;

ServerGames *ServerGames::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock(&lock);
        if (instance == 0) {
            instance = new ServerGames();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

ServerGames::ServerGames() {
    this->gamesList = new vector<GameInfo *>;
}

ServerGames::~ServerGames() {
    while (!gamesList->empty()) {
        gamesList->pop_back();
    }
    delete (gamesList);
}

vector<GameInfo*> *ServerGames::getGamesList() {
    return gamesList;
}
