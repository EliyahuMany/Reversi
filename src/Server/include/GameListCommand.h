//
// Created by orian on 12/31/17.
//

#ifndef SERVER_GAMELISTCOMMAND_H
#define SERVER_GAMELISTCOMMAND_H


#include "Command.h"

using namespace std;

class GameListCommand : public Command {
public:
    GameListCommand(vector<GameInfo> &gameList);

    virtual void execute(vector<string> &args);
};


#endif //SERVER_GAMELISTCOMMAND_H
