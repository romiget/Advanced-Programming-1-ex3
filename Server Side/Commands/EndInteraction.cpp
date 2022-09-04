//
// Created by romrom4444 on 8/28/22.
//

#include "EndInteraction.h"


EndInteraction::EndInteraction(DefaultIO* io) : Command(io) {
}

void EndInteraction::execute(int& k, Metric* metric) {
    this->getIO()->end();
}