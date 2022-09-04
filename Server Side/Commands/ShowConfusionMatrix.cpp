//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include <cmath>
#include "ShowConfusionMatrix.h"
#include "../KNN Algorithm/FileHandler.h"
#include <map>
#include <algorithm>

void ShowConfusionMatrix::execute(int& k, Metric* metric) {
    std::vector<Measurable> realTypes = FileHandler::getMeasurables("data.csv");
    std::vector<Measurable> KNNTypes = FileHandler::getMeasurables("data.csv");
    for (auto & KNNType : KNNTypes) {
        KNNType.setType("");
    }
    ofstream fs("test.csv", ios::out);
    for (auto & KNNType : KNNTypes) {
        FileHandler::classify(KNNType, realTypes, fs, 5, *metric);
    }
    fs.close();
    createConfusionMatrix(realTypes, KNNTypes);
}

ShowConfusionMatrix::ShowConfusionMatrix(DefaultIO &io) : Command(io) {
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
            lines[i].append(to_string((round(KNNTypesCounter[i][j] * 100.0 / realTypesCounter[i]))));
            lines[i].append("%\t");
        }
        str.append(lines[i] + "\n");
    }

    io.write(str);
}
