//
// Created by romrom4444 on 8/28/22.
//

#include "SendClassificationFile.h"
#include <fstream>

SendClassificationFile::SendClassificationFile(DefaultIO &io) : Command(io, <#initializer#>) {
}

string SendClassificationFile::getDescription() {
    return "download results";
}

void SendClassificationFile::execute() {
    fstream fs;
    fs.open("classified.csv", ios::in);
    if (!fs.good()) {
        throw exception();
    }
    string str;
    while(getline(fs, str)) {
        io.write(str);
    }
    fs.close();
}