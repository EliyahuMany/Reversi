/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/CommandsManager.h"
#include "../include/StartCommand.h"

CommandsManager::CommandsManager() {
    commandsMap["start"] = new StartCommand(this->gamesList);
// Add more commands...
}

void CommandsManager::executeCommand(string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    if (commandObj) {
        commandObj->execute(args);
    }
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}