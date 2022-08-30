//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_COMMAND_H
#define SERVER_SIDE_COMMAND_H
#include <string>
#include "../IO/DefaultIO.h"
using namespace std;

class Command {
protected:
    string description;
    DefaultIO io;
public:
    virtual void execute();
    virtual string getDescription();
    virtual DefaultIO& getIO();
    Command(DefaultIO& io);
};
#endif //SERVER_SIDE_COMMAND_H
