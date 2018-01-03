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
    static CommandsManager *getInstance();

    void executeCommand(string command, vector<string> args, vector<pthread_t> threadsVector);

private:
    CommandsManager();

    ~CommandsManager();

    static CommandsManager *instance;
    static pthread_mutex_t lock;
    map<string, Command *> commandsMap;
};


#endif //SERVER_COMMANDMANAGER_H
