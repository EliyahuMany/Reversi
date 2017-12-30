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
    Command(vector<GameInfo> &gamesList);

    virtual void execute(vector<string> &args) = 0;

protected:
    vector<GameInfo> gamesList;
};

#endif //PROJECT_COMMAND_H