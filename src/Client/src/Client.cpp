/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/Client.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>
#include <csignal>

using namespace std;

Client::Client(const char *serverIP, int serverPort, Print &printer) : serverIP(serverIP), serverPort(serverPort),
                                                                       clientSocket(0), printer(printer) {
    cout << "Client" << endl;
}

void Client::connectToServer() {
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
    this->printer.string((char *) "Connected to server");
}

void Client::sendMove(string str) {
    signal(SIGPIPE, SIG_IGN);
    int size = str.size() + 1;
    char move[size];
    strcpy(move, str.c_str());

    int n = write(clientSocket, &size, sizeof(size));
    if (n == -1)
        throw "Error writing move";
    n = write(clientSocket, move, sizeof(move));
    if (n == -1)
        throw "Error writing move";
}

void Client::receiveMove(string &str) {
    signal(SIGPIPE, SIG_IGN);
    int size = 0;
    int n = read(clientSocket, &size, sizeof(int));
    if (n == -1)
        throw "Error reading move";
    char move[size];
    n = read(clientSocket, move, sizeof(move));
    if (strcmp(move, "exit") == 0) {
        printer.string((char *) "server is closed");
        exit(0);
    }
    if (n == -1)
        throw "Error reading move";
    str = move;
}

void Client::getPlayerNum(int *numOfPlayer) {
    int n = read(clientSocket, numOfPlayer, sizeof(*numOfPlayer));
    if (n == -1)
        throw "Error reading move";
}