//
// Created by ido on 8/28/22.
//

#include "UploadFile.h"

void UploadFile::execute() {
    this->getIO().write("Please upload your local train CSV file.");
    string fileName = this->getIO().read();
    //to-do, upload
    this->getIO().write("Upload complete.");
    this->getIO().write("Please upload your local test CSV file.");
    fileName = this->getIO().read();
    //to-do, upload
    this->getIO().write("Upload complete");
}

UploadFile::UploadFile(DefaultIO &io) : Command(io) {
}

string UploadFile::getDescription() {
    return "upload an unclassified data file";
}