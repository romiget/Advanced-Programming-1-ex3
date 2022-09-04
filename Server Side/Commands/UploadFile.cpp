//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"
#include <fstream>
#include <iostream>

void UploadFile::execute(int& k, Metric* metric) {
    ofstream out;
    string str;

    out.open("data.csv", ios::trunc);
    if (!out.good()) {
        throw exception();
    }
    str = io->read();
    while(str != "eof") {
        cout << 1 << endl;
        out << str << endl;
        str = io->read();
    }
    out.close();
    out.open("unclassifiedfile.csv", ios::trunc);
    if (!out.good()) {
        throw exception();
    }
    str = io->read();
    while(str != "eof") {
        out << str << endl;
    }
    out.close();
}

UploadFile::UploadFile(DefaultIO* io) : Command(io) {
}
