#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <algorithm>
#include "IO/SocketIO.h"
#include "CLI.h"
#include <pthread.h>
#include <stdio.h>

using namespace std;

vector<pid_t> threads;

struct start_args {
    int sock;
    int client_sock;
};

void* start(void* args) {
    threads.push_back(gettid());
    struct start_args* arg = (struct start_args*) args;
    auto io = new SocketIO(arg->sock, arg->client_sock);
    CLI cli = CLI(io);
    cli.start();

    const string data_file = "data" + to_string(gettid()) + ".csv";
    const string unclassified_file = "unclassified" + to_string(gettid()) + ".csv";
    const string output_file = "output" + to_string(gettid()) + ".csv";
    const string test_file = "test" + to_string(gettid()) + ".csv";

    remove(data_file.c_str());
    remove(unclassified_file.c_str());
    remove(output_file.c_str());
    remove(test_file.c_str());

    threads.erase(find(threads.begin(), threads.end(), gettid()));

    pthread_exit(NULL);
}

void* timer(void* useless) {
    while(true) {
        sleep(10);
        if (threads.empty()) {
            exit(0);
        }
    }
}

int main(int argc, char* argv[]) {

    //initializing socket
    const int server_port = 1234;
    struct sockaddr_in sin;
    pthread_t tid;

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

    pthread_create(&tid, 0, &timer, NULL);

    unsigned int addr_len = sizeof(client_sin);
    while(true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);

        if (client_sock < 0) {
            perror("couldn't accept connection");
        }

        struct start_args args;
        args.sock = sock;
        args.client_sock = client_sock;

        pthread_create(&tid, 0, &start, &args);
    }
}