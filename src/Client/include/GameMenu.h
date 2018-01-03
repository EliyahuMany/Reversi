//
// Created by orian on 1/1/18.
//

#ifndef RAVERSI_GAMEMENU_H
#define RAVERSI_GAMEMENU_H

#include <iostream>
#include "Print.h"
#include "Players.h"
#include "Client.h"

using namespace std;

class GameMenu {
public:
    GameMenu();

    void menu();

    void localPlayerContact(Print &printer, Client &client);

private:
//    Players *pX, *pO;
};


#endif //RAVERSI_GAMEMENU_H
