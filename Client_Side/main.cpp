//
// Created by ido on 8/12/22.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "IO/SocketIO.h"
#include "CLI.h"

using namespace std;
int main(int argc, char* argv[]) {
    // initializing socket
    const char* ip_address = "127.0.0.1";
    static const int port_no = 1234;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    // memset
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    // connecting to the server
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    // initializing CLI and running it
    SocketIO io = SocketIO(sock);
    CLI cli = CLI(io);
    cli.start();
}