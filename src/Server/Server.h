/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


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
    void handleClient(int clientSocket1, int clientSocket2);
};


#endif //SERVER_SERVER_H
