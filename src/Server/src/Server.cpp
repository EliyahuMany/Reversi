/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/Server.h"
#include "../include/ClientHandler.h"

using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port, CommandsManager &cmd) : port(port), serverSocket(0), cmd(cmd) {
    cout << "Server" << endl;
}

void Server::start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
        throw "Error opening socket";
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }

    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    cout << "Waiting for client connections..." << endl;
    while (true) {
        //first client
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "First client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";

        pthread_t newThread;
        ClientHandler ch(clientSocket, cmd);
        int rc = pthread_create(&newThread, NULL, ch.handleClient, (void *) &ch);
        pthread_join(newThread, NULL);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
        pthread_exit(NULL);
    }
}

void Server::stop() {
    close(serverSocket);
}