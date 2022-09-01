//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include "ClassifyFile.h"
#include "../KNN Algorithm/FileHandler.h"

using namespace std;

void ClassifyFile::execute() {
    Metric metric = this->getMetric();
    fstream fs("cmake-build-debug/test.csv");
    vector<Measurable> measurables = FileHandler::getMeasurables("cmake-build-debug/train.csv");
    fstream output("cmake-build-debug/train.csv", ios::app);
    string line;
    while(getline(fs, line)) {
        Measurable unclassified = FileHandler::createMeasurableFromUnclassified(line);
        FileHandler::classify(unclassified, measurables, output, this->getK(), metric);
    }
}

ClassifyFile::ClassifyFile(DefaultIO &io) : Command(io, <#initializer#>) {
}

string ClassifyFile::getDescription() {
    return "classify data";
}