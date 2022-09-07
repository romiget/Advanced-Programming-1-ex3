//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include "ClassifyFile.h"
#include "../KNN Algorithm/FileHandler.h"
#include <iostream>
#include <unistd.h>
#include "../CLI.h"

using namespace std;

void ClassifyFile::execute(int& k, Metric** metric) {

    const string data_file = "data" + to_string(gettid()) + ".csv";
    const string unclassified_file = "unclassified" + to_string(gettid()) + ".csv";
    const string output_file = "output" + to_string(gettid()) + ".csv";

    fstream fs(unclassified_file);
    vector<Measurable> measurables = FileHandler::getMeasurables(data_file);
    ofstream output(output_file, ios::trunc);
    string line;
    while(getline(fs, line)) {
        Measurable unclassified = FileHandler::createMeasurableFromUnclassified(line);
        FileHandler::classify(unclassified, measurables, output, k, **metric);
    }
    fs.close();
    output.close();
}

ClassifyFile::ClassifyFile(DefaultIO* io) : Command(io) {
}