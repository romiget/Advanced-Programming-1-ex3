//
// Created by romrom4444 on 8/28/22.
//

#include "SendClassificationFile.h"

SendClassificationFile::SendClassificationFile(DefaultIO &io) : Command(io) {
}

string SendClassificationFile::getDescription() {
    return "download results";
}