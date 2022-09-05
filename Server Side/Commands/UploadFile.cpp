//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"
#include <fstream>
#include <iostream>

void UploadFile::execute(int& k, Metric** metric) {
    ofstream out;
    string str;

    out.open("data.csv", ios::trunc);
    if (!out.good()) {
        throw exception();
    }
    str = io->read();
    io->write("got line");
    while(str != "eof") {
        out << str << endl;
        str = io->read();
        io->write("got line");
    }
    out.close();
    out.open("unclassifiedfile.csv", ios::trunc);
    if (!out.good()) {
        throw exception();
    }
    str = io->read();
    io->write("got line");
    while(str != "eof") {
        out << str << endl;
        str = io->read();
        io->write("got line");
    }
    out.close();
}

UploadFile::UploadFile(DefaultIO* io) : Command(io) {
}
