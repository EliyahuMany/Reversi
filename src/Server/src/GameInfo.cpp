/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/GameInfo.h"
#include <unistd.h>
#include <cstring>

GameInfo::GameInfo(string name, int clientSocket1) : gameName(name), clientSocket1(clientSocket1), avail(true) {}

void *GameInfo::gameHandler(void *args) {

    GameInfo *g = (GameInfo *) args;
    int client1Socket = g->getClientSocket1();
    int client2Socket = g->getClientSocket2();

//    //send number for the player for their sign.
//    int playerNum = 1;
//    int n = write(client1Socket, &playerNum, sizeof(playerNum));
//    if (n == -1) {
//        cout << "Error reading buf" << endl;
//        return 0;
//    } else if (n == 0) {
//        cout << "Client disconnected" << endl;
//        return 0;
//    }
//    playerNum = 2;
//    n = write(client2Socket, &playerNum, sizeof(playerNum));
//    if (n == -1) {
//        cout << "Error reading buf" << endl;
//        return 0;
//    } else if (n == 0) {
//        cout << "Client disconnected" << endl;
//        return 0;
//    }


    while (true) {
        int size;
        int n = read(client1Socket, &size, sizeof(size));
        if (n == -1) {
            cout << "Error reading buf" << endl;
            return 0;
        }
        char buf[size];
        bzero(buf, sizeof(buf));
        n = read(client1Socket, &buf, sizeof(buf));
        if (n == -1) {
            cout << "Error reading buf" << endl;
            return 0;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            return 0;
        }
        cout << buf << endl;

        n = write(client2Socket, &size, sizeof(size));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return 0;
        }
        n = write(client2Socket, &buf, sizeof(buf));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return 0;
        }

        //switch sockets.
        int temp = client1Socket;
        client1Socket = client2Socket;
        client2Socket = temp;
    }
}

const string &GameInfo::getName() const {
    return this->gameName;
}

int GameInfo::getClientSocket1() const {
    return clientSocket1;
}

int GameInfo::getClientSocket2() const {
    return clientSocket2;
}

void GameInfo::setClientSocket2(int clientSocket2) {
    GameInfo::clientSocket2 = clientSocket2;
    avail = false;
}
bool GameInfo::getAvail() {
    return this->avail;
}
