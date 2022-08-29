//
// Created by romrom4444 on 8/28/22.
//

#include "StandardIO.h"
#include <iostream>

using namespace std;
string& StandardIO::read() {
    string str;
    cin >> str;
    return str;
}

void write(string str) {
    cout << str << endl;
}

void end() {
    exit(0);
}