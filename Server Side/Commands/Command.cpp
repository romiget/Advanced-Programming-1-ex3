//
// Created by ido on 8/28/22.
//

#include "Command.h"

DefaultIO &Command::getIO() {
    return this->io;
}

int Command::getK() const {
    return this->k;
}
Metric* Command::getMetric() {
    return this->metric;
}

void Command::setK(int k) {
    this->k = k;
}

void Command::setMetric(Metric &metric1) {
    this->metric = &metric1;
}

void Command::setMetric(string &name) {
    if (name == "EUC") {
        auto* euclideanMetric = new EuclideanMetric();
        this->setMetric(*euclideanMetric);
    }
    else if (name == "MAN") {
        auto* manhattanMetric = new ManhattanMetric();
        this->setMetric(*manhattanMetric);
    }
    else if (name == "CHE") {
        auto* chebyshevMetric = new ChebyshevMetric();
        this->setMetric(*chebyshevMetric);
    }
    else
        throw exception();
}

Command::Command(DefaultIO &io, Metric &metric) : io(io) {
    this->io = io;
    this->metric = &metric;
}

Command::Command(DefaultIO &io) : io(io) {
    this->io = io;
    this->metric = new EuclideanMetric();
}

Command::~Command() {
    delete this->metric;
}
