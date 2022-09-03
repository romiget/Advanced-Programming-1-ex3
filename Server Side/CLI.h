//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_CLI_H
#define SERVER_SIDE_CLI_H

#include "Metrics/Metric.h"
#include "Metrics/EuclideanMetric.h"
#include "Metrics/ChebyshevMetric.h"
#include "Metrics/ManhattanMetric.h"
#include "Commands/Command.h"

class CLI {
private:
    vector<Command*> commands;
    DefaultIO io;
    void init();
public:
    void start();
    CLI(DefaultIO &io);
};

#endif //SERVER_SIDE_CLI_H
