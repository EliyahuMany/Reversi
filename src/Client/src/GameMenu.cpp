/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <fstream>
#include <cstdlib>
#include "../include/GameMenu.h"
#include "../include/ConsolePrint.h"
#include "../include/GameFlow.h"
#include "../include/Client.h"
#include "../include/LocalPlayer.h"
#include "../include/RemotePlayer.h"

GameMenu::GameMenu() {}

void GameMenu::menu() {
    int size, choose;
    ConsolePrint printer;

    while (true) {
        printer.string((char *) "Choose an option from the menu:");
        printer.string((char *) "1. Human vs Human");
        printer.string((char *) "2. Human vs AI");
        printer.string((char *) "3. Human vs Wireless Player");
        cin >> choose;
        if (choose == 1 || choose == 2 || choose == 3)
            break;
        printer.string((char *) "Wrong input!");
        cin.clear();
        cin.ignore(100, '\n');
    }
    size = 8;
    GameLogic gameLogic(size);
    switch (choose) {
        case 1: {
            Players *pX = new Human('X', printer);
            Players *pO = new Human('O', printer);
            GameFlow game = GameFlow(pX, pO, gameLogic, printer);
            game.run();
            delete pX;
            delete pO;
            break;
        }
        case 2: {
            Players *pX = new Human('X', printer);
            Players *pO = new AIPlayer('O', gameLogic, printer);
            GameFlow game = GameFlow(pX, pO, gameLogic, printer);
            game.run();
            delete pX;
            delete pO;
            break;
        }
        case 3: {
            int playerNum;
            ifstream cFile;
            cFile.open("client_config.txt");
            string ip, port;
            if (cFile.is_open()) {
                getline(cFile, ip);
                getline(cFile, port);
            } else
                exit(1);
            cFile.close();
            Client client(ip.c_str(), atoi(port.c_str()), printer);
            try {
                client.connectToServer();
            } catch (const char *m) {
                printer.connectionFailed(m);
                exit(1);
            }
            cin.ignore();
            localPlayerContact(printer, client, playerNum);

            Players *pX;
            Players *pO;
            if (playerNum == 1) {
                pX = new LocalPlayer('X', client, printer);
                pO = new RemotePlayer('O', client, printer);
            } else {
                pX = new RemotePlayer('X', client, printer);
                pO = new LocalPlayer('O', client, printer);
            }
            GameFlow game = GameFlow(pX, pO, gameLogic, printer);
            game.run();
            delete pX;
            delete pO;
            break;
        }
    }
}

void GameMenu::localPlayerContact(Print &printer, Client &client, int &playerNum) {
    while (true) {
        string buffer, getMsg, command;
        char *buf;
        printer.string((char *) "Enter command to the server:");
//        while (true) {
        getline(cin, buffer);
        buf = new char[buffer.length()];
        strcpy(buf, buffer.c_str());
        client.sendMove(buffer);

        command = strtok(buf, " ");
//            if (command == "start" || command == "join" || command == "list_games")
//                break;
//        }
        memset(buf, NULL, buffer.length());
        client.receiveMove(getMsg);
        if (strcmp(getMsg.c_str(), "exit") == 0) {
            printer.string((char *) "server is close");
            exit(0);
        }
        if (getMsg == "-1") {
            if (command == "start")
                getMsg = "Room already exist choose again!";
            else if (command == "join")
                getMsg = "There is no such game name!";
        } else if ((command == "start") || command == "join") {
            if (command == "start") {
                playerNum = 1;
            } else {
                playerNum = 2;
            }
            char msg[getMsg.size()+1];
            strcpy(msg, getMsg.c_str());
            printer.string(msg);
            if (command == "start") {
                client.receiveMove(getMsg);
                if (strcmp(getMsg.c_str(), "exit") == 0) {
                    printer.string((char *) "server is close");
                    exit(0);
                }
                printer.string(msg);
            }
            break;
        }
        char msg[getMsg.size()];
        strcpy(msg, getMsg.c_str());
        printer.string(msg);
        delete[] buf;
    }
}
