//
// Created by ido on 8/28/22.
//

#include "Command.h"

DefaultIO* Command::getIO() {
    return this->io;
}

Command::Command(DefaultIO* io) : io(io) {
    this->io = io;
}
