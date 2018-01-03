//
// Created by eliyahu on 12/31/17.
//

#include <cstdlib>
#include "../include/JoinCommand.h"
#include "../include/ServerGames.h"

using namespace std;

void JoinCommand::execute(vector<string> &args) {
    vector<GameInfo *> *gamesList = ServerGames::getInstance()->getGamesList();
    int clientSocket = atoi(args[0].c_str());
    string msg = "";
    bool isInList = false;
    gamesList[2];
    vector<GameInfo *>::iterator it;
    for (it = gamesList->begin(); it != gamesList->end(); it++) {
        if (!(*it)->getName().compare(args[1])) {
            (*it)->setClientSocket2(atoi(args[0].c_str()));
            isInList = true;
            break;
        }
    }
    if (!isInList) {
        msg.append("-1");
        this->commandNotify(clientSocket, msg);
        return;
    }
    msg.append("Connected to " + (*it)->getName());
    this->commandNotify(clientSocket, msg);
    GameInfo *g = *it;
    pthread_t gameThread;
    pthread_create(&gameThread, NULL, &GameInfo::gameHandler, (void *) g);
    pthread_exit(NULL);
}