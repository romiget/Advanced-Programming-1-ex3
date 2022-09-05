//
// Created by romrom4444 on 8/28/22.
//

#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "SocketIO.h"

using namespace std;

SocketIO::SocketIO(int server_sock, int client_sock) {
    this->sock = server_sock;
    this->client_sock = client_sock;
}

void SocketIO::write(string str) {
    size_t data_len = str.size();
    //sending data
    ssize_t sent_bytes = send(client_sock, str.c_str(), data_len, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

string SocketIO::read() {
    char buffer[256] = {'\0'};
    int expected_data_len = sizeof(buffer);
    ssize_t read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes < 0) {
        perror("error reading from client");
    }
    string str;
    for (char c : buffer) {
        if (c) {
            str.append(&c);
        } else {
            break;
        }
    }
    return str;
}

void SocketIO::end() {
    close(client_sock);
}