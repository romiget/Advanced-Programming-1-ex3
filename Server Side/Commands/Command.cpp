//
// Created by ido on 8/28/22.
//

#include "Command.h"

string Command::getDescription() {
    return this->description;
}

DefaultIO &Command::getIO() {
    return this->io;
}

Command::Command(DefaultIO &io) : io(io) {
    this->io = io;
}

int Command::getK() const {
    return this->k;
}
Metric& Command::getMetric() {
    return this->metric;
}

void Command::setK(int k) {
    this->k = k;
}

void Command::setMetric(Metric &metric) {
    this->metric = metric;
}

void Command::setMetric(string &name) {
    if (name == "EUC")
        this->metric = EuclideanMetric();
    else if (name == "MAN")
        this->metric = ManhattanMetric();
    else if (name == "CHE")
        this->metric = ChebyshevMetric();
    else
        throw exception();
}
