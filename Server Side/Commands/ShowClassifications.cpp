//
// Created by romrom4444 on 8/28/22.
//

#include "ShowClassifications.h"
#include <fstream>

ShowClassifications::ShowClassifications(DefaultIO &io) : Command(io, <#initializer#>) {
}

string ShowClassifications::getDescription() {
    return "display results";
}

void ShowClassifications::execute() {
    fstream fs;
    fs.open("classified.csv", ios::in);
    if (!fs.good()) {
        throw exception();
    }
    string str;
    while(getline(fs, str)) {
        io.write(str);
    }
    fs.close();
}