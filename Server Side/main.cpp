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

// struct for the thread function's arguments
struct start_args {
    int sock;
    int client_sock;
};

void* start(void* args) {
    // putting the thread in a vector for the timer thread to use
    threads.push_back(gettid());

    // running the program
    struct start_args* arg = (struct start_args*) args;
    auto io = new SocketIO(arg->sock, arg->client_sock);
    CLI cli = CLI(io);
    cli.start();

    // setting the file names according to the current thread
    const string data_file = "data" + to_string(gettid()) + ".csv";
    const string unclassified_file = "unclassified" + to_string(gettid()) + ".csv";
    const string output_file = "output" + to_string(gettid()) + ".csv";
    const string test_file = "test" + to_string(gettid()) + ".csv";

    // deleting all thread-specific files.
    remove(data_file.c_str());
    remove(unclassified_file.c_str());
    remove(output_file.c_str());
    remove(test_file.c_str());

    // erasing the thread from the vector of active threads
    threads.erase(find(threads.begin(), threads.end(), gettid()));

    pthread_exit(NULL);
}

void* timer(void* useless) {
    // checks every 10 seconds if there are still clients connected.
    // if not, it closes the program (there wouldn't be allocated memory or
    // open sockets since the threads handled that when they closed.
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
    sin.sin_addr.s_addr = INADDR_ANY;The case where
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
        // accepting a client and creating a thread that handles that client
        // so that we can continue accepting new clients while still answering
        // the other clients.
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