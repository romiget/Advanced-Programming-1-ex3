//
// Created by romrom4444 on 8/28/22.
//

#include "EndInteraction.h"


EndInteraction::EndInteraction(DefaultIO &io) : Command(io) {
    this->io = io;
}

void EndInteraction::execute() {
    io.end();
}

string EndInteraction::getDescription() {
    return "exit";
}