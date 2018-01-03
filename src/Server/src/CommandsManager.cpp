/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/CommandsManager.h"
#include "../include/StartCommand.h"
#include "../include/JoinCommand.h"
#include "../include/GameListCommand.h"

CommandsManager *CommandsManager::instance = 0;
pthread_mutex_t CommandsManager::lock;

CommandsManager *CommandsManager::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock(&lock);
        if (instance == 0) {
            instance = new CommandsManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

CommandsManager::CommandsManager() {
    commandsMap["start"] = new StartCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["list_games"] = new GameListCommand();
}

void CommandsManager::executeCommand(string command, vector<string> args,vector<pthread_t> threadsVector) {
    Command *commandObj = commandsMap[command];
    if (commandObj) {
        commandObj->execute(args,threadsVector);
    }
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}
