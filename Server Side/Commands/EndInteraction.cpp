//
// Created by romrom4444 on 8/28/22.
//

#include "EndInteraction.h"


EndInteraction::EndInteraction(DefaultIO &io) : Command(io, <#initializer#>) {
}

void EndInteraction::execute() {
    this->getIO().end();
}

string EndInteraction::getDescription() {
    return "exit";
}