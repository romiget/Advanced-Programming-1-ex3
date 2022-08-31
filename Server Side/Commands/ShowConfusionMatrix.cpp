//
// Created by romrom4444 on 8/28/22.
//

#include <fstream>
#include <cmath>
#include "ShowConfusionMatrix.h"
#include "../KNN Algorithm/FileHandler.h"

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
    int realTypesCounter[3];
    int KNNTypesCounter[3][3];
    for (int i = 0; i < realTypes.size(); i++) {
        if (realTypes[i].getType() == "Iris-setosa") {
            realTypesCounter[0]++;
            if (KNNTypes[i].getType() == "Iris-setosa") {
                KNNTypesCounter[0][0]++;
            } else if (KNNTypes[i].getType() == "Iris-versicolor")
                KNNTypesCounter[0][1]++;
            else
                KNNTypesCounter[0][2]++;
        } else if (realTypes[i].getType() == "Iris-versicolor") {
            realTypesCounter[1]++;
            if (KNNTypes[i].getType() == "Iris-setosa")
                KNNTypesCounter[1][0]++;
            else if (KNNTypes[i].getType() == "Iris-versicolor")
                KNNTypesCounter[1][1]++;
            else
                KNNTypesCounter[1][2]++;
        } else {
            realTypesCounter[2]++;
            if (KNNTypes[i].getType() == "Iris-setosa")
                KNNTypesCounter[2][0]++;
            else if(KNNTypes[i].getType() == "Iris-versicolor")
                KNNTypesCounter[2][1]++;
            else
                KNNTypesCounter[2][2]++;
        }
    }
    this->getIO().write("\t\tIris-setosa Iris-versicolor Iris-virginica\n");
    string lines[3];
    lines[0] = "Iris-setosa\t";
    lines[1] = "Iris-versicolor\t";
    lines[2] = "Iris-virginica\t";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            lines[i].append(to_string((round(KNNTypesCounter[i][j] * 100.0 / realTypesCounter[i]))));
            lines[i].append("%\t");
        }
        this->getIO().write(lines[i] + "\n");
    }
}
