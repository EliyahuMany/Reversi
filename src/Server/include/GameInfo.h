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
    /**
     * constructor
     * @param name - game name
     * @param clientSocket1 - first client socket
     */
    GameInfo(string name, int clientSocket1);

    /**
     * @return string - the game name
     */
    const string &getName() const;

    /**
     * @return int - first client socket
     */
    int getClientSocket1() const;

    /**
     * @return int - second client socket
     */
    int getClientSocket2() const;

    /**
    * set second client socket
    * @param clientSocket2
    */
    void setClientSocket2(int clientSocket2);

    /**
     * func for handle the game - thread
     * @param args
     * @return
     */
    static void *gameHandler(void *args);

    /**
     * @return bool - if game is available or not
     */
    bool getAvail();

private:
    string gameName;
    int clientSocket1;
    int clientSocket2;
    bool avail;
};

#endif //SERVER_GAMEINFO_H