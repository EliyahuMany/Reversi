/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {
    ifstream sFile;
    sFile.open("../../../exe/server_config.txt");
    string port;
    if (sFile.is_open())
        getline(sFile, port);
    else
        return 0;
    sFile.close();
    Server server(atoi(port.c_str()));
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
    server.stop();
}
