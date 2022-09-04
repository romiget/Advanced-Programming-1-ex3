//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"
#include <fstream>
#include <iostream>

void UploadFile::execute() {
    fstream in;
    string str;

    cout << "Train:" << endl;
    string fileName = io->read();
    in.open(fileName, ios::in);
    if (!in) {
        throw exception();
    }
    if (!in.good()) {
        throw exception();
    }
    while(getline(in, str)) {
        io->write(str);
    }
    io->write("eof");
    in.close();
    cout << "Upload Complete" << endl;
    cout << "Unclassified:" << endl;
    fileName = this->getIO()->read();
    in.open(fileName, ios::in);
    if (!in.good()) {
        throw exception();
    }
    while(getline(in, str)) {
        io->write(str);
    }
    io->write("eof");
    in.close();
    cout << "Upload Complete" << endl;
}

string UploadFile::getDescription() {
    return "upload an unclassified data file";
}

UploadFile::UploadFile(DefaultIO *io) : Command(io) {
}
