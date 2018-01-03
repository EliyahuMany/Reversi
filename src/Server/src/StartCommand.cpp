//
// Created by orian on 12/30/17.
//

#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include "../include/StartCommand.h"
#include "../include/ServerGames.h"

void StartCommand::execute(vector<string> &args) {
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
    GameInfo *game = new GameInfo(args[1], atoi(args[0].c_str()));
    gamesList->push_back(game);
    //write to the client to wait.
    msg = "Waiting to another player...";
    this->commandNotify(clientSocket, msg);
}
