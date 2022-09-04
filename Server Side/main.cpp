#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "KNN Algorithm/FileHandler.h"
#include <exception>
#include "Metrics/EuclideanMetric.h"
#include "IO/StandardIO.h"
#include <algorithm>
#include <cmath>
#include "IO/SocketIO.h"
#include "CLI.h"

using namespace std;
int main(int argc, char* argv[]) {

    //initializing socket
    const int server_port = 1234;
    struct sockaddr_in sin;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("couldn't create socket for server");
    }
    //memset
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    //binding
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("couldn't bind server socket");
    }
    //waiting for connection of a client
    if (listen(sock, 5) < 0) {
        perror("couldn't listen to socket");
    }
    //accepting the client
    static struct sockaddr_in client_sin;

    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("couldn't accept connection");
    }

    SocketIO io = SocketIO(sock, client_sock);
    CLI cli = CLI(io);
    cli.start();
}