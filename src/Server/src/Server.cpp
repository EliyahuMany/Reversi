/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <sstream>
#include "../include/Server.h"
#include "../include/ServerGames.h"

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define MAX_COMMAND_LENGTH 50

static void *acceptClients(void *);

static void *handleClient(void *);

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

    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    pthread_create(&serverThreadId, NULL, acceptClients, (void *) serverSocket);
    pthread_join(serverThreadId, NULL);
}

void Server::stop() {
    pthread_cancel(serverThreadId);
    close(serverSocket);
    cout << "Server stopped" << endl;
}

static void *acceptClients(void *socket) {
    long serverSocket = (long) socket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);

    cout << "Waiting for client connections..." << endl;
    while (true) {
        //first client
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";

        pthread_t newThread;
        int rc = pthread_create(&newThread, NULL, handleClient, (void *) clientSocket);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
    }
}

void *handleClient(void *socket) {
    long clientSocket = (long) socket;
    int size;
    int n = read(clientSocket, &size, sizeof(size));
    if (n == -1) {
        cout << "Error reading buf" << endl;
        return 0;
    }
    char buf[size];
    string command;
    n = read(clientSocket, &buf, sizeof(buf));
    if (n == -1) {
        cout << "Error reading buf" << endl;
        return 0;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return 0;
    }
    //parse the string to command and args
    char str[strlen(buf)];
    strcpy(str, buf);
    char *w;
    vector<string> args;
    //convert the client socket to string and send it as first arg to the commands.
    ostringstream ss;
    ss << clientSocket;
    args.push_back(ss.str());
    w = strtok(buf, " ");
    if (w)
        command = w;
    while (w) {
        w = strtok(NULL, " ");
        if (w)
            args.push_back(w);
    }
    CommandsManager::getInstance()->executeCommand(command, args);

}