//
// Created by orian on 12/30/17.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"

using namespace std;

class StartCommand : public Command {
public:
    virtual void execute(vector<string> &args);
};


#endif //SERVER_STARTCOMMAND_H
