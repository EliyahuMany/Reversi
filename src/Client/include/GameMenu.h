/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef RAVERSI_GAMEMENU_H
#define RAVERSI_GAMEMENU_H

#include <iostream>
#include "Print.h"
#include "Players.h"
#include "Client.h"

using namespace std;

class GameMenu {
public:
    /**
     * constructor
     */
    GameMenu();

    /**
     * run the menu
     */
    void menu();

    /**
     * contact with the server to send commands
     * @param printer
     * @param client
     */
    void localPlayerContact(Print &printer, Client &client, int &);

private:
//    Players *pX, *pO;
};


#endif //RAVERSI_GAMEMENU_H
