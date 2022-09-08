//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include <cmath>
#include "ShowConfusionMatrix.h"
#include "../KNN Algorithm/FileHandler.h"
#include <map>
#include <algorithm>
#include <unistd.h>

void ShowConfusionMatrix::execute(int& k, Metric** metric) {

    // initializing thread-specific file names
    const string data_file = "data" + to_string(gettid()) + ".csv";
    const string test_file = "test" + to_string(gettid()) + ".csv";

    // getting the measurables from the classified data files and classifying them ourselves
    std::vector<Measurable> realTypes = FileHandler::getMeasurables(data_file);
    std::vector<Measurable> KNNTypes = FileHandler::getMeasurables(data_file);
    for (auto & KNNType : KNNTypes) {
        KNNType.setType("");
    }
    ofstream fs(test_file, ios::out);
    for (auto & KNNType : KNNTypes) {
        FileHandler::classify(KNNType, realTypes, fs, 5, **metric);
    }
    fs.close();
    createConfusionMatrix(realTypes, KNNTypes);
}

ShowConfusionMatrix::ShowConfusionMatrix(DefaultIO* io) : Command(io) {
}

void ShowConfusionMatrix::createConfusionMatrix(const vector<Measurable>& realTypes, const vector<Measurable>& KNNTypes) {
    // initializing counters
    vector<int> realTypesCounter;
    vector<string> types;
    vector<vector<int>> KNNTypesCounter;
    vector<int> zeros;

    for (const Measurable & realType : realTypes) {
        if(find(types.begin(), types.end(), realType.getType()) == types.end()) {
            // counting the amount of types and setting a vector of zeros
            // to be as large as the amount of types
            types.push_back(realType.getType());
            zeros.push_back(0);
        }
    }
    // initializing KNNTypesCounter to be a square matrix of zeros,
    // of a size according to the number of types
    for (int i = 0; i < types.size(); i++) {
        KNNTypesCounter.push_back(zeros);
    }
    realTypesCounter = zeros;
    // counting the amount of objects of each type,
    // in reality and in what our algorithm measured
    for (int i = 0; i < realTypes.size(); i++) {
        for(int j = 0; j < types.size(); j++) {
            if(realTypes[i].getType() == types[j]) {
                realTypesCounter[j]++;
                for(int k = 0; k < types.size(); k++) {
                    if(KNNTypes[i].getType() == types[k]) {
                        KNNTypesCounter[k][j]++;
                    }
                }
            }
        }
    }

    // sending the result

    string str = "\t";

    for (const string& type : types) {
        str.append(type);
        str.append("\t");
    }
    str.append("\n");
    vector<string> lines = types;
    for (int i = 0; i < types.size(); i++) {
        for (int j = 0; j < types.size(); j++) {
            lines[i].append("\t");
            lines[i].append(to_string(((int) round(KNNTypesCounter[i][j] * 100.0 / realTypesCounter[i]))));
            lines[i].append("%\t");
        }
        str.append(lines[i] + "\n");
    }

    io->write(str);
}
