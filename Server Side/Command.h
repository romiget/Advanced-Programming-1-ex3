//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_COMMAND_H
#define SERVER_SIDE_COMMAND_H
#include <string>
#include "DefaultIO.h"
using namespace std;

class Command {
private:
    string& description;
    DefaultIO& defaultIo;
public:
    virtual void execute();
};
#endif //SERVER_SIDE_COMMAND_H
