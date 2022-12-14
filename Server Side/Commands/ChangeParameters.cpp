//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include <iostream>

void ChangeParameters::execute(int& k, Metric** metric) {
    // writing the current parameters to the client
    io->write(to_string(k) + "," + (*metric)->getType());
    // reading input from the client
    string input = io->read();
    // checking if the client input valid parameters
    if (input == "Invalid")
        return;
    // separating k and metric by comma
    // we trust that we have valid input since the client handles that
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
