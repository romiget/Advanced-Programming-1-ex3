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
    int k = 5;
    Metric* metric;
    void init();
    void close();
public:
    void start();
    int getK() const;
    void setK(int k);
    Metric* getMetric();
    void setMetric(Metric& metric);
    void setMetric(string& name);
    CLI(DefaultIO &io);
};

#endif //SERVER_SIDE_CLI_H
