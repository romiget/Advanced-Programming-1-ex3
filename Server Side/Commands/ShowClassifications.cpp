//
// Created by romrom4444 on 8/28/22.
//

#include "ShowClassifications.h"

ShowClassifications::ShowClassifications(DefaultIO &io) : Command(io) {
    this->io = io;
}

string ShowClassifications::getDescription() {
    return "display results";
}