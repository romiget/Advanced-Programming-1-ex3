//
// Created by romrom4444 on 8/28/22.
//

#include "GetClassifications.h"
#include <fstream>
#include <iostream>

string GetClassifications::getDescription() {
    return "display results";
}

void GetClassifications::execute() {
    string str = io->read();
    while (str != "eof") {
        cout << str << endl;
        // letting the server know we got the line
        io->write("got line");
        str = io->read();
    }
}

GetClassifications::GetClassifications(DefaultIO* io) : Command(io) {
}