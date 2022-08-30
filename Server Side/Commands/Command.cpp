//
// Created by ido on 8/28/22.
//

#include "Command.h"

void Command::execute() {
    //should've overridden that.
    throw exception();
}

string Command::getDescription() {
    return this->description;
}

DefaultIO &Command::getIO() {
    return this->io;
}

Command::Command(DefaultIO &io) {
    this->io = io;
}

int Command::getK() {
    return this->k;
}
string& Command::getMetric() {
    return this->metricName;
}

void Command::setK(int k) {
    this->k = k;
}

void Command::setMetric(string &name) {
    this->metricName = name;
}