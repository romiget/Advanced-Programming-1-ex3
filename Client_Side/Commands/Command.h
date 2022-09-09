//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_COMMAND_H
#define SERVER_SIDE_COMMAND_H
#include <string>
#include "../IO/DefaultIO.h"

// The general command class. This class is polymorphic, and is meant to be
// implemented as one of the seven commands used in the CLI.

using namespace std;

class Command {
private:
    string description;
protected:
    DefaultIO* io;
public:
    // executes the command
    virtual void execute() = 0;
    // returns a description of the command
    virtual string getDescription();
    virtual DefaultIO* getIO();
    explicit Command(DefaultIO* io);
    virtual ~Command() = default;
};
#endif //SERVER_SIDE_COMMAND_H
