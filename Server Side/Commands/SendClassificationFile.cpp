//
// Created by romrom4444 on 8/28/22.
//

#include "SendClassificationFile.h"
#include <fstream>

SendClassificationFile::SendClassificationFile(DefaultIO &io) : Command(io) {
}

void SendClassificationFile::execute(int& k, Metric* metric) {
    fstream fs;
    fs.open("output.csv", ios::in);
    if (!fs.good()) {
        throw exception();
    }
    string str;
    while(getline(fs, str)) {
        io.write(str);
    }
    io.write("eof");
    fs.close();
}