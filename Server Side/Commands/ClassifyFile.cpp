//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include "ClassifyFile.h"
#include "../KNN Algorithm/FileHandler.h"

using namespace std;

void ClassifyFile::execute() {
    fstream fs("unclassifiedfile.csv");
    vector<Measurable> measurables = FileHandler::getMeasurables("data.csv");
    ofstream output("output.csv", ios::trunc);
    string line;
    while(getline(fs, line)) {
        Measurable unclassified = FileHandler::createMeasurableFromUnclassified(line);
        FileHandler::classify(unclassified, measurables, output, this->getK(), *this->getMetric());
    }

    fs.close();
    output.close();
}

ClassifyFile::ClassifyFile(DefaultIO &io) : Command(io) {
}

string ClassifyFile::getDescription() {
    return "classify data";
}