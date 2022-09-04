//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include "../IO/DefaultIO.h"

void ChangeParameters::execute() {
    io.write(to_string(getK()) + "," + getMetric()->getType());
    string input = io.read();
    setK(stoi(input.substr(0, input.find(','))));
    string metric = input.substr(input.find(',') + 1, input.size() - input.find(','));
    setMetric(metric);
}

ChangeParameters::ChangeParameters(DefaultIO &io) : Command(io) {
}
