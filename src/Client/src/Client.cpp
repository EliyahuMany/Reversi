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

void Client::sendMove(char *move) {
    int n = write(clientSocket, move, strlen(move));
    if (n == -1)
        throw "Error writing move";
}

void Client::receiveMove(char *move) {
    int size;
    int n = read(clientSocket, &size, sizeof(int));
    if (n == -1)
        throw "Error reading move";
    n = read(clientSocket, move, size);
    if (n == -1)
        throw "Error reading move";
}

void Client::getPlayerNum(int &numOfPlayer) {
    int n = read(clientSocket, &numOfPlayer, sizeof(numOfPlayer));
    if (n == -1)
        throw "Error reading move";
}