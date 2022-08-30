//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"

void UploadFile::execute() {

}

UploadFile::UploadFile(DefaultIO &io) : Command(io) {
    this->io = io;
}

string UploadFile::getDescription() {
    return "upload an unclassified data file";
}