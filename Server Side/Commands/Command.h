//
// Created by ido on 8/28/22.
//

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
    DefaultIO& io;
public:
    virtual void execute(int& k, Metric* metric) = 0;
    virtual DefaultIO& getIO();
    explicit Command(DefaultIO &io);
    virtual ~Command() = default;
};
#endif //SERVER_SIDE_COMMAND_H
