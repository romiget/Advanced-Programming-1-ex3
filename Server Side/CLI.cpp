//
// Created by romrom4444 on 8/28/22.
//

#include "CLI.h"
#include "Commands/UploadFile.h"
#include "Commands/ChangeParameters.h"

void CLI::init() {
    commands.push_back(UploadFile());
    commands.push_back(ChangeParameters());
}

void CLI::start() {
    init();
    int choice = 0;
    while (choice != 7) {
        string s = "Welcome to the KNN Classifier Server. Please choose an option:\n";
        for (int i = 0; i < commands.size(); i++) {
            s.append(to_string(i));
            s.append(". ");
            s.append((commands.begin() + i - 1)->getDescription());
            s.append("\n");
        }
        choice = stoi(io.read());
        (commands.begin() + choice - 1)->execute();
    }
}

CLI::CLI(DefaultIO& io) {
    this->io = io;
}