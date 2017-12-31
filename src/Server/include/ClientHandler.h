//
// Created by orian on 12/29/17.
//

#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

#include <iostream>
#include <cstring>
#include "CommandsManager.h"

using namespace std;

class ClientHandler {
public:
    ClientHandler(int socket, CommandsManager &cmd);

    static void *handleClient(void *args);

private:
    int clientSocket;
    CommandsManager cmd;
};


#endif //SERVER_CLIENTHANDLER_H
