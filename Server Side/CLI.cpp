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
#include <iostream>

void CLI::init() {
    // initializing the commands and putting them in a vector
    // so that access to the commands is easy using an index variable.
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
        choice = stoi(io->read());
        commands[choice - 1]->execute(k, &metric);
    }
    close();
}

CLI::CLI(DefaultIO* io) {
    this->io = io;
    this->k = 5;
    this->metric = new EuclideanMetric();
}

void CLI::close() {
    delete io;
    for (int i = (int) commands.size() - 1; i >= 0; i--) {
        Command* temp = commands[i];
        commands.pop_back();
        delete temp;
    }
    delete metric;
}

int CLI::getK() const {
    return this->k;
}
Metric* CLI::getMetric() {
    return this->metric;
}

void CLI::setK(int k) {
    this->k = k;
}

void CLI::setMetric(Metric &metric1) {
    this->metric = &metric1;
}

void CLI::setMetric(string &name) {
    if (name == "EUC") {
        auto* euclideanMetric = new EuclideanMetric();
        this->setMetric(*euclideanMetric);
    }
    else if (name == "MAN") {
        auto* manhattanMetric = new ManhattanMetric();
        this->setMetric(*manhattanMetric);
    }
    else if (name == "CHE") {
        auto* chebyshevMetric = new ChebyshevMetric();
        this->setMetric(*chebyshevMetric);
    }
    else
        throw exception();
}