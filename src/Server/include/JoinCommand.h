/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include "GameInfo.h"
#include "Command.h"
#include <vector>

class JoinCommand : public Command {
public:
    /**
     * execute the command
     * @param args args for the command
     * @param threadsVector
     */
    virtual void execute(vector<string> &args, vector<pthread_t> *threadsVector);
};


#endif //SERVER_JOINCOMMAND_H
