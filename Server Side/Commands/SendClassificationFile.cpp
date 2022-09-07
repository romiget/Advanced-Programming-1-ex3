//
// Created by romrom4444 on 8/28/22.
//

#include "SendClassificationFile.h"
#include <fstream>
#include <unistd.h>

SendClassificationFile::SendClassificationFile(DefaultIO* io) : Command(io) {
}

void SendClassificationFile::execute(int& k, Metric** metric) {
    fstream fs;
    const string output_file = "output" + to_string(gettid()) + ".csv";

    fs.open(output_file, ios::in);
    if (!fs.good()) {
        throw exception();
    }
    string str;
    while(getline(fs, str)) {
        io->write(str);
        io->read();
    }
    io->write("eof");
    fs.close();
}