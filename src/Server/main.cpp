/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "include/Server.h"
#include "include/CommandsManager.h"
#include <fstream>

using namespace std;

int main() {
    CommandsManager cmd;
    ifstream sFile;
    sFile.open("server_config.txt");
    string port;
    if (sFile.is_open())
        getline(sFile, port);
    else
        return 0;
    sFile.close();
    Server server(atoi(port.c_str()),cmd);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
    server.stop();
}
