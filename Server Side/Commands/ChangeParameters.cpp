//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include <iostream>

void ChangeParameters::execute(int& k, Metric** metric) {
    io->write(to_string(k) + "," + (*metric)->getType());
    string input = io->read();
    if (input == "Invalid")
        return;
    k = stoi(input.substr(0, input.find(',')));
    string newMetric = input.substr(input.find(',') + 1, 3);
    if (newMetric == "EUC") {
        *metric = new EuclideanMetric();
    }
    else if (newMetric == "MAN") {
        *metric = new ManhattanMetric();
    }
    else if (newMetric == "CHE") {
        *metric = new ChebyshevMetric();
    }
    else {
        delete metric;
        throw exception();
    }
}

ChangeParameters::ChangeParameters(DefaultIO* io) : Command(io) {
}
