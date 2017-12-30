//
// Created by orian on 12/28/17.
//

#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H

#include <map>
#include "Command.h"
#include "GameInfo.h"

using namespace std;

class CommandsManager {
public:
    CommandsManager();

    ~CommandsManager();

    void executeCommand(string command, vector<string> args);

private:
    map<string, Command *> commandsMap;
    vector<GameInfo> gamesList;
};


#endif //SERVER_COMMANDMANAGER_H
