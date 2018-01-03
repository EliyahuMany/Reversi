/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include "../include/StartCommand.h"
#include "../include/ServerGames.h"

pthread_mutex_t startMutex;

void StartCommand::execute(vector<string> &args, vector<pthread_t> *threadsVector) {
    vector<GameInfo *> *gamesList = ServerGames::getInstance()->getGamesList();
    int clientSocket = atoi(args[0].c_str());
    string msg;

    for (vector<GameInfo *>::iterator it = gamesList->begin(); it != gamesList->end(); it++) {
        if (!strcmp((*it)->getName().c_str(), args[0].c_str())) {
            msg = "-1";
            this->commandNotify(clientSocket, msg);
            return;
        }
    }
    pthread_mutex_lock(&startMutex);
    GameInfo *game = new GameInfo(args[1], atoi(args[0].c_str()));
    gamesList->push_back(game);
    pthread_mutex_unlock(&startMutex);
    //write to the client to wait.
    msg = "Waiting to another player...";
    this->commandNotify(clientSocket, msg);
}
