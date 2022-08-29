//
// Created by romrom4444 on 8/28/22.
//

#include "ShowConfusionMatrix.h"

ShowConfusionMatrix::ShowConfusionMatrix(DefaultIO &io) : Command(io) {
    this->io = io;
}

string ShowConfusionMatrix::getDescription() {
    return "display algorithm confusion matrix";
}
