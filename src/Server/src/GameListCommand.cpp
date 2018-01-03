/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <cstdlib>
#include <unistd.h>
#include "../include/GameListCommand.h"
#include "../include/ServerGames.h"

void GameListCommand::execute(vector<string> &args,vector<pthread_t> *threadsVector) {
    vector<GameInfo *> *gamesList = ServerGames::getInstance()->getGamesList();
    int clientSocket = atoi(args[0].c_str());
    vector<GameInfo *>::iterator it;
    string listToPrint = "";

    for (it = gamesList->begin(); it != gamesList->end(); it++) {
        if ((*it)->getAvail())
            listToPrint.append((*it)->getName() + "\n");
    }
    if (listToPrint == "")
        listToPrint.append("No games active");
    //send the list to the user.
    this->commandNotify(clientSocket, listToPrint);
}
