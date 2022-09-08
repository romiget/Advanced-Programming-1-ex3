//
// Created by ido on 8/28/22.
//

// The general command class. This class is polymorphic, and is meant to be
// implemented as one of the seven commands used in the CLI.

#ifndef SERVER_SIDE_COMMAND_H
#define SERVER_SIDE_COMMAND_H
#include <string>
#include "../IO/DefaultIO.h"
#include "../Metrics/Metric.h"
#include "../Metrics/EuclideanMetric.h"
#include "../Metrics/ManhattanMetric.h"
#include "../Metrics/ChebyshevMetric.h"

using namespace std;

class Command {
private:
    string description;
protected:
    DefaultIO* io;
public:
    // executes the command
    virtual void execute(int& k, Metric** metric) = 0;
    explicit Command(DefaultIO* io);
    virtual ~Command() = default;
};
#endif //SERVER_SIDE_COMMAND_H
