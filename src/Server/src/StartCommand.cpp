//
// Created by orian on 12/30/17.
//

#include <cstdlib>
#include "../include/StartCommand.h"

StartCommand::StartCommand(vector<GameInfo> &gamesList) : Command(gamesList) {}

void StartCommand::execute(vector<string> &args) {
    for (int i = 0; i < this->gamesList.size(); i++) {
        if (!this->gamesList[i].getName().compare(args[1])) {
            return;
        }
    }
    GameInfo game(args[1], atoi(args[0].c_str()));
    this->gamesList.push_back(game);
}
