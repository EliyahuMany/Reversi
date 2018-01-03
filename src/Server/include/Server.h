/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <cstdlib>
#include <vector>
#include "CommandsManager.h"

using namespace std;

class Server {
public:
    /**
     * constructor - make the server
     * @param port - port of the server
     */
    Server(int port);

    /**
     * start the server
     */
    void start();

    /**
     * stop the server
     */
    void stop();

private:
    int port;
    int serverSocket; // the socket's file descriptor
    vector<pthread_t> serverThreads;
    pthread_t serverThreadId;
};


#endif //SERVER_SERVER_H
