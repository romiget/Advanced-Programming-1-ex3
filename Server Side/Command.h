//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_COMMAND_H
#define SERVER_SIDE_COMMAND_H
#include <string>
#include "DefaultIO.h"
using namespace std;

class Command {
    string& description;
    DefaultIO& defaultIo;
public:
    virtual void execute();
    string getDescription();
    Command(DefaultIO &defaultIo, string &description);
    DefaultIO& getIO();
};
#endif //SERVER_SIDE_COMMAND_H
