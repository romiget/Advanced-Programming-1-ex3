//
// Created by romrom4444 on 8/28/22.
//

#include "ReceiveClassificationFile.h"
#include <fstream>

string ReceiveClassificationFile::getDescription() {
    return "download results";
}

void ReceiveClassificationFile::execute() {
    ofstream ofs;
    ofs.open("output.csv", ios::trunc);
    if (!ofs) {
        throw exception();
    }
    string str = io->read();
    while(str != "eof") {
        ofs << str << endl;
        str = io->read();
    }
}

ReceiveClassificationFile::ReceiveClassificationFile(DefaultIO* io) : Command(io) {
}