//
// Created by ido on 8/28/22.
//

#include "Command.h"

void Command::execute() {
    //should've overridden that.
    throw exception();
}

string Command::getDescription() {
    return this->description;
}

DefaultIO &Command::getIO() {
    return this->defaultIo;
}

