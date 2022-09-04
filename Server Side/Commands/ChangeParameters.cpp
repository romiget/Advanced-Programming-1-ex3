//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include "../IO/DefaultIO.h"

void ChangeParameters::execute(int& k, Metric* metric) {
    io.write(to_string(k) + "," + metric->getType());
    string input = io.read();
    k = (stoi(input.substr(0, input.find(','))));
    string newMetric = input.substr(input.find(',') + 1, input.size() - input.find(','));
    Metric* temp = metric;
    if (newMetric == "EUC") {
        metric = new EuclideanMetric();
    }
    else if (newMetric == "MAN") {
        metric = new ManhattanMetric();
    }
    else if (newMetric == "CHE") {
        metric = new ChebyshevMetric();
    }
    else
        throw exception();
    delete temp;
}

ChangeParameters::ChangeParameters(DefaultIO &io) : Command(io) {
}
