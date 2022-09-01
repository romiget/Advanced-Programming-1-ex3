//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include <cmath>
#include "ShowConfusionMatrix.h"
#include "../KNN Algorithm/FileHandler.h"
#include <map>
#include <algorithm>

void ShowConfusionMatrix::execute() {
    std::vector<Measurable> realTypes = FileHandler::getMeasurables("data.csv");
    std::vector<Measurable> KNNTypes = FileHandler::getMeasurables("data.csv");
    for (auto & KNNType : KNNTypes) {
        KNNType.setType("");
    }
    fstream fs("test.csv", ios::out);
    for (auto & KNNType : KNNTypes) {
        FileHandler::classify(KNNType, realTypes, fs, this->getK(), this->getMetric());
    }
    fs.close();
    createConfusionMatrix(realTypes, KNNTypes);
}

ShowConfusionMatrix::ShowConfusionMatrix(DefaultIO &io) : Command(io) {
}

string ShowConfusionMatrix::getDescription() {
    return "display algorithm confusion matrix";
}

void ShowConfusionMatrix::createConfusionMatrix(const vector<Measurable>& realTypes, const vector<Measurable>& KNNTypes) {
    vector<int> realTypesCounter;
    vector<string> types;
    vector<vector<int>> KNNTypesCounter;

    vector<int> zeros;
    for (const Measurable & realType : realTypes) {
        if(find(types.begin(), types.end(), realType.getType()) == types.end()) {
            types.push_back(realType.getType());
            zeros.push_back(0);
        }
    }
    for (int i = 0; i < types.size(); i++) {
        KNNTypesCounter.push_back(zeros);
    }
    realTypesCounter = zeros;
    for (const auto & realType : realTypes) {
        for(int j = 0; j < types.size(); j++) {
            if(realType.getType() == types[j]) {
                realTypesCounter[j]++;
                for(int k = 0; k < types.size(); k++) {
                    if(KNNTypes[k].getType() == types[k]) {
                        KNNTypesCounter[j][k]++;
                    }
                }
            }
        }
    }

    for (const string& type : types) {
        io.write(type);
        io.write("\t");
    }
    io.write("\n");
    vector<string> lines = types;
    for (int i = 0; i < types.size(); i++) {
        for (int j = 0; j < types.size(); j++) {
            lines[i].append(to_string((round(KNNTypesCounter[i][j] * 100.0 / realTypesCounter[i]))));
            lines[i].append("%\t");
        }
        io.write(lines[i] + "\n");
    }
}
