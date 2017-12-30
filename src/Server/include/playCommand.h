//
// Created by orian on 12/27/17.
//

#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H

#include "Command.h"

class playCommand: public Command {
public:
    virtual void execute(vector<string> args);
};

#endif //SERVER_PLAYCOMMAND_H
