/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H

#include "GameInfo.h"
#include <string>
#include <vector>

using namespace std;

class Command {
public:
    /**
     * execute the command
     * @param args args for the command
     * @param threadsVector
     */
    virtual void execute(vector<string> &args, vector<pthread_t> *threadsVector) = 0;

    /**
     * notify the clients on the command success
     * @param clientSocket - client socket
     * @param msg - msg to writ to the client
     */
    void commandNotify(int clientSocket, string msg);
};

#endif //PROJECT_COMMAND_H