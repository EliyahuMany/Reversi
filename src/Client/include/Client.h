//
// Created by orian on 12/8/17.
//

#ifndef RAVERSI_CLIENT_H
#define RAVERSI_CLIENT_H


#include "Print.h"

class Client {
public:
    Client(const char *serverIP, int serverPort,Print &printer);

    int connectToServer();

    void sendMove(char *move);

    void receiveMove(char *move);

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    Print &printer;
};


#endif //RAVERSI_CLIENT_H
