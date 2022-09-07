//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void UploadFile::execute(int& k, Metric** metric) {
    ofstream out;
    string str;

    const string data_file = "data" + to_string(gettid()) + ".csv";
    const string unclassified_file = "unclassified" + to_string(gettid()) + ".csv";

    out.open(data_file, ios::trunc);
    if (!out.good()) {
        throw exception();
    }
    str = io->read();
    while(str != "eof") {
        out << str << endl;
        io->write("got line");
        str = io->read();
    }
    out.close();
    out.open(unclassified_file, ios::trunc);
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
