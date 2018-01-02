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
    virtual void execute(vector<string> &args) = 0;

    void commandNotify(int clientSocket, string msg);
};

#endif //PROJECT_COMMAND_H