//
// Created by romrom4444 on 8/28/22.
//

#include "ShowClassifications.h"
#include <fstream>
#include <iostream>

ShowClassifications::ShowClassifications(DefaultIO* io) : Command(io) {
}

void ShowClassifications::execute(int& k, Metric** metric) {
    fstream fs;
    fs.open("output.csv", ios::in);
    if (!fs.good()) {
        throw exception();
    }
    string str;
    string output;
    int i = 1;
    while(getline(fs, str)) {
        output.append(to_string(i));
        output.append(". ");
        output.append(str);
        io->write(output);
        io->read();
        i++;
        output = "";
    }
    io->write("eof");
    fs.close();
}