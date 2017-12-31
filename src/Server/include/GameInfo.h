/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef SERVER_GAMEINFO_H
#define SERVER_GAMEINFO_H

#include <string>
#include <iostream>

using namespace std;

class GameInfo {
public:
    GameInfo(string name, int clientSocket1);

    const string &getName() const;

    int getClientSocket1() const;

    int getClientSocket2() const;

    void setClientSocket2(int clientSocket2);

    static void *gameHandler(void *args);

private:
    string gameName;
    int clientSocket1;
    int clientSocket2;
};

#endif //SERVER_GAMEINFO_H