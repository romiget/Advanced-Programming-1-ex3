//
// Created by romrom4444 on 8/28/22.
//

#include "GetConfusionMatrix.h"
#include <string>
#include <iostream>

void GetConfusionMatrix::execute() {
    string matrix = io.read();
    cout << matrix << endl;
}

GetConfusionMatrix::GetConfusionMatrix(DefaultIO &io) : Command(io) {
}