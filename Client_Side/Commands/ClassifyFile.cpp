//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include "ClassifyFile.h"

using namespace std;

void ClassifyFile::execute() {
    // no work on the client side is done
}

string ClassifyFile::getDescription() {
    return "classify data";
}

ClassifyFile::ClassifyFile(DefaultIO* io): Command(io){
}