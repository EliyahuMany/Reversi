//
// Created by orian on 1/1/18.
//

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
    Players *pX, *pO;

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
        case 1:
            pX = new Human('X', printer);
            pO = new Human('O', printer);
            break;
        case 2:
            pX = new Human('X', printer);
            pO = new AIPlayer('O', gameLogic, printer);
            break;
        case 3:
            this->localPlayerContact(printer, pX, pO);
            break;
    }
    GameFlow game = GameFlow(pX, pO, gameLogic, printer);
    game.run();
}

void GameMenu::localPlayerContact(Print &printer, Players *pX, Players *pO) {
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

    while (true) {
        string buffer;
        printer.string((char *) "Enter command to the server:");
        cin.ignore();
        getline(cin, buffer);
        char buf[buffer.length()];
        bzero(buf, buffer.length());
        for (int i = 0; i < buffer.length(); i++) {
            buf[i] = buffer.at(i);
        }
        client.sendMove(buf);

        string command = strtok(buf, " ");

        client.receiveMove(buf);
        if (strcmp(buf, "-1") == 0) {
            if (strcmp(command.c_str(), "start") == 0)
                strcpy(buf, "Room already exist choose again!");
            else if (strcmp(command.c_str(), "join") == 0)
                strcpy(buf, "There is no such game name!");
            printer.string(buf);
        } else if (strcmp(command.c_str(), "start") == 0 || strcmp(command.c_str(), "join") == 0) {
            printer.string(buf);
            break;
        }
    }

    client.getPlayerNum(playerNum);
    if (playerNum == 1) {
        pX = new LocalPlayer('X', client, printer);
        pO = new RemotePlayer('O', client, printer);
    } else if (playerNum == 2) {
        pX = new RemotePlayer('X', client, printer);
        pO = new LocalPlayer('O', client, printer);
    }
}