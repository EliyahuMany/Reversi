//
// Created by eliyahu on 12/31/17.
//

#include <cstdlib>
#include <unistd.h>
#include "../include/JoinCommand.h"

using namespace std;

JoinCommand::JoinCommand(vector<GameInfo> &gamesList) : Command(gamesList) {}

void JoinCommand::execute(vector<string> &args) {
    int i, clientSocket = atoi(args[0].c_str());
    string msg = "";
    bool isInList = false;
    for (i = 0; i < this->gamesList.size(); i++) {
        if (!this->gamesList[i].getName().compare(args[1])) {
            this->gamesList[i].setClientSocket2(atoi(args[0].c_str()));
            isInList = true;
            break;
        }
    }
    if (!isInList) {
        msg.append("There is no such game name");
        this->commandNotify(clientSocket, msg);
        return;
    }
    pthread_t gameThread;
    pthread_create(&gameThread, NULL, this->gamesList[i].gameHandler, (void *) &this->gamesList[i]);
    pthread_exit(NULL);

}