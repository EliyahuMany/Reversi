//
// Created by orian on 12/31/17.
//

#include <cstdlib>
#include <unistd.h>
#include "../include/GameListCommand.h"

void GameListCommand::execute(vector<string> &args) {
    int clientSocket = atoi(args[0].c_str());
    vector<GameInfo>::iterator it;
    string listToPrint = "";

    for (it = this->gamesList.begin(); it != this->gamesList.end(); it++) {
        listToPrint.append((*it).getName() + "/n");
    }
    if (listToPrint == "")
        listToPrint.append("No games active");
    //send the list to the user.
    this->commandNotify(clientSocket, listToPrint);
}
