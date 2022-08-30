//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include "../IO/DefaultIO.h"

void ChangeParameters::execute() {
    this->getIO().write(
            "The current KNN parameters are: K = " + to_string(getK()) + ", distance metric = " + getMetric());
    string input = this->getIO().read();
    bool flag = false;
    if (input.empty()) return;
    try {
        if (input[1] == ' ' || stoi(input.substr(0, 2)) == 10) {
            this->setK(input[0] - '0');
            if (this->getK() == 10)
                flag = true;
        } else {
            this->getIO().write("Invalid value for K");
        }
        string metric;
        if (flag) {
            metric = input.substr(3, 3);
        } else {
            metric = input.substr(2, 3);
        }
        if (metric == "EUC" || metric == "MAN" || metric == "CHE")
            this->setMetric(metric);
        else
            this->getIO().write("Invalid metric name");
    } catch (exception &e) {
        this->getIO().write("Invalid input");
    }
}

ChangeParameters::ChangeParameters(DefaultIO &io) : Command(io) {
}

string ChangeParameters::getDescription() {
    return "algorithm settings";
}
