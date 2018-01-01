//
// Created by orian on 12/29/17.
//

#include <unistd.h>
#include <sstream>
#include "../include/ClientHandler.h"

ClientHandler::ClientHandler(int socket, CommandsManager &cmd) : clientSocket(socket), cmd(cmd) {}

void *ClientHandler::handleClient(void *args) {
    ClientHandler ch = *(ClientHandler *) args;
    char *buf;
    string command;

    while (true) {
        int n = read(ch.clientSocket, &buf, sizeof(buf));
        if (n == -1) {
            cout << "Error reading buf" << endl;
            return 0;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            return 0;
        }

        //parse the string to command and args
        char str[strlen(buf) + 1];
        strcpy(str, buf);
        char *w;
        vector<string> args;
        //convert the client socket to string and send it as first arg to the commands.
        ostringstream ss;
        ss << ch.clientSocket;
        args.push_back(ss.str());
        w = strtok(buf, " ");
        if (w)
            command = w;
        while (w) {
            w = strtok(NULL, " ");
            args.push_back(w);
        }
        ch.cmd.executeCommand(command, args);
        if (command == "close")
            break;
    }
}
