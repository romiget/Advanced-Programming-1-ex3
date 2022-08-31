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
    int k = 5;
    Metric metric = EuclideanMetric();
protected:
    DefaultIO io;
public:
    virtual void execute();
    virtual string getDescription();
    virtual DefaultIO& getIO();
    explicit Command(DefaultIO& io);
    int getK();
    void setK(int k);
    Metric& getMetric();
    void setMetric(Metric& metric);
    void setMetric(string& name);
};
#endif //SERVER_SIDE_COMMAND_H
