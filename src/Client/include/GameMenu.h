//
// Created by orian on 1/1/18.
//

#ifndef RAVERSI_GAMEMENU_H
#define RAVERSI_GAMEMENU_H

#include <iostream>
#include "Print.h"
#include "Players.h"

using namespace std;

class GameMenu {
public:
    GameMenu();

    void menu();

    void localPlayerContact(Print &printer, Players *pX,Players *pO);
};


#endif //RAVERSI_GAMEMENU_H
