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
    string fileName;
    cin >> fileName;
    in.open(fileName, ios::in);
    if (!in) {
        cout << "No such file!" << endl;
        return;
    }
    while(getline(in, str)) {
        io->write(str);
        io->read();
    }
    io->write("eof");
    in.close();
    cout << "Upload Complete" << endl;
    cout << "Unclassified:" << endl;
    cin >> fileName;
    in.open(fileName, ios::in);
    if (!in) {
        cout << "No such file!" << endl;
        return;
    }
    while(getline(in, str)) {
        io->write(str);
        io->read();
    }
    io->write("eof");
    io->read();
    in.close();
    cout << "Upload Complete" << endl;
}

string UploadFile::getDescription() {
    return "upload an unclassified data file";
}

UploadFile::UploadFile(DefaultIO *io) : Command(io) {
}
