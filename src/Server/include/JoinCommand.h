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
    JoinCommand(vector<GameInfo> &gamesList);

    virtual void execute(vector<string> &args);
};


#endif //SERVER_JOINCOMMAND_H
