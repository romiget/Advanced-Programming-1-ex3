//
// Created by ido on 8/28/22.
//

#include "Command.h"

string Command::getDescription() {
    return this->description;
}

DefaultIO &Command::getIO() {
    return this->io;
}

Command::Command(DefaultIO &io) : io(io) {
    this->io = io;
}