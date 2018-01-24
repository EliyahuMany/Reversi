/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <sstream>
#include <csignal>
#include "../include/Server.h"
#include "../include/ServerGames.h"


using namespace std;
#define MAX_CONNECTED_CLIENTS 30
#define MAX_THREADS 1

struct args {
    int serverSocket;
    int clientSocket;
    vector<pthread_t> *threadsVector;
    ThreadPool *pool;
};

static void *acceptClients(void *);

static void *handleClient(void *);

Server::Server(int port) : port(port), serverSocket(0) {
    threadPool = new ThreadPool(MAX_THREADS);
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

    args *args1 = new args();
    args1->serverSocket = serverSocket;
    args1->threadsVector = &this->serverThreads;
    args1->pool = threadPool;

    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    pthread_create(&serverThreadId, NULL, acceptClients, (void *) args1);
}

void Server::stop() {
    signal(SIGPIPE, SIG_IGN);
    cout << "Server stopped" << endl;
    vector<GameInfo *> *gamesList = ServerGames::getInstance()->getGamesList();
    threadPool->terminate();
    for (int i = 0; i < this->serverThreads.size(); i++) {
        pthread_cancel(this->serverThreads[i]);
        pthread_join(this->serverThreads[i], NULL);
    }
    char exit[5] = "exit";
    int size = strlen(exit) + 1;
    for (vector<GameInfo *>::iterator it = gamesList->begin(); it != gamesList->end(); it++) {
        int n = write((*it)->getClientSocket1(), &size, sizeof(size));
        if (n == -1) {
            cout << "Client doesn't exist" << endl;
        }
        n = write((*it)->getClientSocket1(), &exit, sizeof(exit));
        if (n == -1) {
            cout << "Client doesn't exist" << endl;
        }
        n = write((*it)->getClientSocket2(), &size, sizeof(size));
        if (n == -1) {
            cout << "Client doesn't exist" << endl;
        }
        n = write((*it)->getClientSocket2(), &exit, sizeof(exit));
        if (n == -1) {
            cout << "Client doesn't exist" << endl;
        }
        close((*it)->getClientSocket2());
        close((*it)->getClientSocket2());
    }
    pthread_cancel(serverThreadId);
    pthread_join(serverThreadId, NULL);
    close(serverSocket);
    delete(threadPool);
}

static void *acceptClients(void *obj) {
    args *args1 = (args *) obj;
    int serverSocket = args1->serverSocket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);

    cout << "Waiting for client connections..." << endl;
    while (true) {
        //first client
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";

        args1->clientSocket = clientSocket;
        Task* task = new Task(handleClient, (void *) args1);
        args1->pool->addTask(task);
//        pthread_t newThread;
//        int rc = pthread_create(&newThread, NULL, handleClient, (void *) args1);
//        if (rc) {
//            cout << "Error: unable to create thread, " << rc << endl;
//            exit(-1);
//        }
//        args1->threadsVector->push_back(newThread);

    }
}

void *handleClient(void *obj) {
    signal(SIGPIPE, SIG_IGN);
    args *args1 = (args *) obj;
    int clientSocket = args1->clientSocket;
    int size;
    while (true) {
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
        CommandsManager::getInstance()->executeCommand(command, args, args1->threadsVector);
        if (command == "start" || command == "join")
            break;
    }

}
