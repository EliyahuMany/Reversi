//
// Created by orian on 12/30/17.
//

#include <cstdlib>
#include <unistd.h>
#include "../include/StartCommand.h"

StartCommand::StartCommand(vector<GameInfo> &gamesList) : Command(gamesList) {}

void StartCommand::execute(vector<string> &args) {
    int clientSocket = atoi(args[0].c_str());

    for (int i = 0; i < this->gamesList.size(); i++) {
        if (this->gamesList[i].getName().compare(args[1])) {
            exit(-1);
        }
    }
    GameInfo game(args[1], atoi(args[0].c_str()));
    this->gamesList.push_back(game);
    //write to the client to wait.
    string msg = "Waiting to another player...";
    this->commandNotify(clientSocket, msg);
}
