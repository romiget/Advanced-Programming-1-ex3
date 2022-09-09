//
// Created by romrom4444 on 8/28/22.
//

#include "GetConfusionMatrix.h"
#include <string>
#include <iostream>

void GetConfusionMatrix::execute() {
    // getting the confusion matrix from the server and printing it
    string matrix = io->read();
    cout << matrix << endl;
}

string GetConfusionMatrix::getDescription() {
    return "display algorithm confusion matrix";
}

GetConfusionMatrix::GetConfusionMatrix(DefaultIO* io) : Command(io) {
}