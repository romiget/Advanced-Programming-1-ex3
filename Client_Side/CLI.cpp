//
// Created by romrom4444 on 8/28/22.
//

#include "CLI.h"
#include "Commands/UploadFile.h"
#include "Commands/ChangeParameters.h"
#include "Commands/ClassifyFile.h"
#include "Commands/GetClassifications.h"
#include "Commands/ReceiveClassificationFile.h"
#include "Commands/GetConfusionMatrix.h"
#include "Commands/EndInteraction.h"
#include <iostream>

void CLI::init() {
    auto uploadFile = new UploadFile(io);
    auto changeParameters = new ChangeParameters(io);
    auto classifyFile = new ClassifyFile(io);
    auto showClassifications = new GetClassifications(io);
    auto sendClassificationFile = new ReceiveClassificationFile(io);
    auto showConfusionMatrix = new GetConfusionMatrix(io);
    auto endInteraction = new EndInteraction(io);
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
            s.append(to_string(i + 1));
            s.append(". ");
            s.append(commands[i]->getDescription());
            s.append("\n");
        }
        cout << s << endl;
        cin >> choice;
        io->write(to_string(choice));
        commands[choice]->execute();
    }
    close();
}

CLI::CLI(DefaultIO* io) {
    this->io = io;
}

void CLI::close() {
    delete io;
    for (int i = (int) commands.size() - 1; i >= 0; i--) {
        Command* temp = commands[i];
        commands.pop_back();
        delete temp;
    }
}
