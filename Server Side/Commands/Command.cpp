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

Command::Command(DefaultIO &Io, string &description)
        : Io(Io), description(description) {
    this->description = description;
    this->Io = Io;
}

DefaultIO &Command::getIO() {
    return this->Io;
}

