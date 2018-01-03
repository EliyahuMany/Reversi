/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef SERVER_GAMELISTCOMMAND_H
#define SERVER_GAMELISTCOMMAND_H


#include "Command.h"

using namespace std;

class GameListCommand : public Command {
public:
    /**
     * execute the command
     * @param args args for the command
     * @param threadsVector
     */
    virtual void execute(vector<string> &args, vector<pthread_t> *threadsVector);
};


#endif //SERVER_GAMELISTCOMMAND_H
