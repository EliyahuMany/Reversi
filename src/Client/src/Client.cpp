//
// Created by orian on 12/8/17.
//

#include "../include/Client.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

using namespace std;

Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
    cout << "Client" << endl;
}

int Client::connectToServer() {
    int s;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }

    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }

    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    serverAddress.sin_port = htons(serverPort);

    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;

    int n = read(clientSocket, &s, sizeof(s));
    if (n == -1) {
        cout << "Reading failed" << endl;
        return 0;
    }
    cout << s << endl;
    return s;
}

void Client::sendMove(char *move) {
    int n = write(clientSocket, move, sizeof(move));
    if (n == -1)
        throw "Error writing move";
}

void Client::receiveMove(char *move) {
    int n = read(clientSocket, move, sizeof(move));
    if (n == -1)
        throw "Error reading move";
}