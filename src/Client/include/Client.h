/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_CLIENT_H
#define RAVERSI_CLIENT_H


#include "Print.h"

class Client {
public:
    /**
     * constructor, make the client by the these ip and port
     * @param serverIP - the IP for the server
     * @param serverPort - the port
     * @param printer - print - the printer of the game.
     */
    Client(const char *serverIP, int serverPort, Print &printer);

    /***
     * connect to the server
     * @return the number of the player 1/2
     */
    void connectToServer();

    /**
     * write the given massage to the server
     * @param move - massage from the player
     */
    void sendMove(char *move);

    /**
    * read a masssage from the server to his parama
    * @param move - char* to save the massage
    */
    void receiveMove(char *move);

    void getPlayerNum(int* numOfPlayer);

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    Print &printer;
};


#endif //RAVERSI_CLIENT_H
