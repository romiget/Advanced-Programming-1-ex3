//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include "../IO/DefaultIO.h"

void ChangeParameters::execute() {
    this->getIO().write("The current KNN parameters are: K = " + to_string(getK()) + ", distance metric = " + getMetric());
    string input = this->getIO().read();
    if (input.empty()) return;
    try {
        if (input[1] == ' ') {
            this->setK(input[0] - '0');
        } else {
            this->getIO().write("Invalid value for K");
        }
        string metric = input.substr(2, 3);
        if (metric == "EUC" || metric == "MAN" || metric == "CHE")
            this->setMetric(metric);
        else
            this->getIO().write("Invalid metric name");
    } catch (exception& e) {
        this->getIO().write("Invalid input");
    }
}

int ChangeParameters::getK() {
    return this->k;
}
string& ChangeParameters::getMetric() {
    return this->metricName;
}

void ChangeParameters::setK(int k) {
    this->k = k;
}

void ChangeParameters::setMetric(string &name) {
    this->metricName = name;
}
