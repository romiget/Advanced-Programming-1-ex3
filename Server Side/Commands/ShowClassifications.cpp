//
// Created by romrom4444 on 8/28/22.
//

#include "ShowClassifications.h"
#include <fstream>
#include <iostream>
#include <unistd.h>

ShowClassifications::ShowClassifications(DefaultIO* io) : Command(io) {
}

void ShowClassifications::execute(int& k, Metric** metric) {
    fstream fs;
    const string output_file = "output" + to_string(gettid()) + ".csv";

    fs.open(output_file, ios::in);
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