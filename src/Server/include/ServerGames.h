//
// Created by orian on 1/2/18.
//

#ifndef SERVER_SERVERGAMES_H
#define SERVER_SERVERGAMES_H

#include <vector>
#include "GameInfo.h"
#include "CommandsManager.h"

using namespace std;

class ServerGames {
public:
    static ServerGames *getInstance();

    vector<GameInfo> *getGamesList();

private:
    // A singleton
    ServerGames();

    ~ServerGames();

    static ServerGames *instance;
    static pthread_mutex_t lock;
    vector<GameInfo> *gamesList;
};

#endif //SERVER_SERVERGAMES_H
