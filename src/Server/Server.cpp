//
// Created by orian on 12/8/17.
//

#include "Server.h"
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port) : port(port), serverSocket(0) {
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

    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    while (true) {
        cout << "Waiting for client connections..." << endl;

        int clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "First client connected" << endl;
        if (clientSocket1 == -1)
            throw "Error on accept";
        int num_of_client = 1;
        int n = write(clientSocket1, &num_of_client, sizeof(num_of_client));
        if (n == -1)
            throw "Error on write the client number";

        int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Second client connected" << endl;
        if (clientSocket2 == -1)
            throw "Error on accept";
        num_of_client = 2;
        n = write(clientSocket2, &num_of_client, sizeof(num_of_client));
        if (n == -1)
            throw "Error on write to first client to start";

        num_of_client = 1;
        n = write(clientSocket1, &num_of_client, sizeof(num_of_client));
        if (n == -1)
            throw "Error on write the client number";

        handleClient(clientSocket1, clientSocket2);

        close(clientSocket1);
        close(clientSocket2);
    }
}

void Server::stop() {
    close(serverSocket);
}

void Server::handleClient(int clientSocket1, int clientSocket2) {
    char *buf;

    while (true) {
        int n = read(clientSocket1, &buf, sizeof(buf));
        if (n == -1) {
            cout << "Error reading buf" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            return;
        }

        n = write(clientSocket2, &buf, sizeof(buf));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }

        //switch sockets.
        int temp = clientSocket1;
        clientSocket1 = clientSocket2;
        clientSocket2 = temp;
    }
}
