//
// Created by romrom4444 on 8/28/22.
//

#include "ClassifyFile.h"

using namespace std;


ClassifyFile::ClassifyFile(DefaultIO &io) : Command(io) {
}

string ClassifyFile::getDescription() {
    return "classify data";
}