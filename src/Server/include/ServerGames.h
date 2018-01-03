/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#ifndef SERVER_SERVERGAMES_H
#define SERVER_SERVERGAMES_H

#include <vector>
#include "GameInfo.h"
#include "CommandsManager.h"

using namespace std;

class ServerGames {
public:
    /**
     * make the object only 1 time
     * @return an object from this class.
     */
    static ServerGames *getInstance();

    /**
     * @return vector<GameInfo *> - the games list
     */
    vector<GameInfo *> *getGamesList();

private:
    // A singleton
    ServerGames();

    ~ServerGames();

    static ServerGames *instance;
    static pthread_mutex_t lock;
    vector<GameInfo *> *gamesList;
};

#endif //SERVER_SERVERGAMES_H
