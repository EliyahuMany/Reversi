//
// Created by eliyahu on 12/31/17.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include "GameInfo.h"
#include "Command.h"
#include <vector>

class JoinCommand : public Command {
public:
    virtual void execute(vector<string> &args,vector<pthread_t> threadsVector);
};


#endif //SERVER_JOINCOMMAND_H
