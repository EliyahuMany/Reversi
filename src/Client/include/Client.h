//
// Created by orian on 12/8/17.
//

#ifndef RAVERSI_CLIENT_H
#define RAVERSI_CLIENT_H


class Client {
public:
    Client(const char *serverIP, int serverPort);

    int connectToServer();

    void sendMove(char *move);

    void receiveMove(char *move);

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //RAVERSI_CLIENT_H
