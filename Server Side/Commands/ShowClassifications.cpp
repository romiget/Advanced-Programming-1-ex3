//
// Created by romrom4444 on 8/28/22.
//

#include "ShowClassifications.h"
#include <fstream>

ShowClassifications::ShowClassifications(DefaultIO &io) : Command(io) {
}

string ShowClassifications::getDescription() {
    return "display results";
}

void ShowClassifications::execute() {
    fstream fs;string metric =
    fs.open("output.csv", ios::in);
    if (!fs.good()) {
        throw exception();
    }
    string str;
    while(getline(fs, str)) {
        io.write(str);
    }
    io.write("eof");
    fs.close();
}