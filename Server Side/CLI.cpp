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
    auto* uploadFile = new UploadFile(io);
    auto* changeParameters = new ChangeParameters(io);
    auto* classifyFile = new ClassifyFile(io);
    auto* showClassifications = new ShowClassifications(io);
    auto* sendClassificationFile = new SendClassificationFile(io);
    auto* showConfusionMatrix = new ShowConfusionMatrix(io);
    auto* endInteraction = new EndInteraction(io);
    commands.push_back(uploadFile);
    commands.push_back(changeParameters);
    commands.push_back(classifyFile);
    commands.push_back(showClassifications);
    commands.push_back(sendClassificationFile);
    commands.push_back(showConfusionMatrix);
    commands.push_back(endInteraction);
}

void CLI::start() {
    init();
    int choice = 0;
    while (choice != 7) {
        string s = "Welcome to the KNN Classifier Server. Please choose an option:\n";
        for (int i = 0; i < commands.size(); i++) {
            s.append(to_string(i));
            s.append(". ");
            s.append((*commands.begin() + i - 1)->getDescription());
            s.append("\n");
        }
        io.write(s);
        choice = stoi(io.read());
        (*commands.begin() + choice - 1)->execute();
    }
}

CLI::CLI(DefaultIO &io) {
}

void CLI::close() {
    for (auto & command : commands) {
        delete command;
    }
}
