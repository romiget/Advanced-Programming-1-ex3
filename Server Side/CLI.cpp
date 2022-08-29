//
// Created by romrom4444 on 8/28/22.
//

#include "CLI.h"
#include "Commands/UploadFile.h"
#include "Commands/ChangeParameters.h"
#include "Commands/ClassifyFile.h"
#include "Commands/ShowClassifications.h"
#include "Commands/SendClassificationFile.h"
#include "Commands/ShowConfusionMatrix.h"
#include "Commands/EndInteraction.h"

void CLI::init() {
    commands.push_back(UploadFile(io));
    commands.push_back(ChangeParameters(io));
    commands.push_back(ClassifyFile(io));
    commands.push_back(ShowClassifications(io));
    commands.push_back(SendClassificationFile(io));
    commands.push_back(ShowConfusionMatrix(io));
    commands.push_back(EndInteraction(io));
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
        io.write(s);
        choice = stoi(io.read());
        (commands.begin() + choice - 1)->execute();
    }
}

CLI::CLI(DefaultIO& io) {
    this->io = io;
}