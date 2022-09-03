//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"
#include <fstream>
#include <iostream>

void UploadFile::execute() {
    ifstream in;
    ofstream out;
    string str;

    io.write("train:");
    string fileName = io.read();
    in.open(fileName, ios::in);
    if (!in) {
        throw exception();
    }
    if (!in.good()) {
        throw exception();
    }
    out.open("data.csv", ios::trunc);
    if (!out.good()) {
        throw exception();
    }
    while(getline(in, str)) {
        cout << 1 << endl;
        out << str << endl;
    }
    out.close();
    in.close();
    io.write("Upload complete.");
    io.write("unclassified:");
    fileName = this->getIO().read();
    in.open(fileName, ios::in);
    if (!in.good()) {
        throw exception();
    }
    out.open("unclassifiedfile.csv", ios::trunc);
    if (!out.good()) {
        throw exception();
    }
    while(getline(in, str)) {
        out << str << endl;
    }
    out.close();
    in.close();
    io.write("Upload complete");
}

UploadFile::UploadFile(DefaultIO &io) : Command(io) {
}

string UploadFile::getDescription() {
    return "upload an unclassified data file";
}
