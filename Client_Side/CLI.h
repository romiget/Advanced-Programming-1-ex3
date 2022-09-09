//
// Created by romrom4444 on 8/28/22.
//

// This class is the user's interface of options. Lets the user
// choose an option and runs the according command for that option.

#ifndef SERVER_SIDE_CLI_H
#define SERVER_SIDE_CLI_H
#include <vector>
#include "Commands/Command.h"

class CLI {
private:
    vector<Command*> commands;
    DefaultIO* io;
    // initializes objects needed to run the program
    void init();
public:
    // runs the loop of asking for a choice and receiving a choice
    void start();
    // releases all allocated heap memory
    void close();
    explicit CLI(DefaultIO* io);
};

#endif //SERVER_SIDE_CLI_H
