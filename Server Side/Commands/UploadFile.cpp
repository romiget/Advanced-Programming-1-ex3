//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"
#include <fstream>

void UploadFile::execute() {
    fstream in, out;
    string str;

    io.write("train:");
    string fileName = io.read();
    in.open(fileName, ios::in);
    out.open("data.csv", ios::trunc);
    while(getline(in, str)) {
        out << str << endl;
    }
    out.close();
    in.close();
    io.write("Upload complete.");
    io.write("unclassified:");
    fileName = this->getIO().read();
    in.open(fileName, ios::in);
    out.open("unclassified.csv", ios::trunc);
    while(getline(in, str)) {
        out << str << endl;
    }
    out.close();
    in.close();
    this->getIO().write("Upload complete");
}

UploadFile::UploadFile(DefaultIO &io) : Command(io, <#initializer#>) {
}

string UploadFile::getDescription() {
    return "upload an unclassified data file";
}