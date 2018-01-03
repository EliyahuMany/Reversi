/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H

#include <map>
#include "Command.h"
#include "GameInfo.h"

using namespace std;

class CommandsManager {
public:
    /**
     * make the object only 1 time
     * @return an object from this class.
     */
    static CommandsManager *getInstance();

    /**
     * call to the correct command
     * @param command
     * @param args
     * @param threadsVector
     */
    void executeCommand(string command, vector<string> args, vector<pthread_t> *threadsVector);

private:
    //singleton
    CommandsManager();

    ~CommandsManager();

    static CommandsManager *instance;
    static pthread_mutex_t lock;
    map<string, Command *> commandsMap;
};


#endif //SERVER_COMMANDMANAGER_H
