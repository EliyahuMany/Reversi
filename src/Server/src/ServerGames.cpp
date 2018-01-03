/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

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
