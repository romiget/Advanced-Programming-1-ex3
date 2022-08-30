//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_COMMAND_H
#define SERVER_SIDE_COMMAND_H
#include <string>
#include "../IO/DefaultIO.h"
using namespace std;

class Command {
private:
    string description;
    DefaultIO io;
    int k = 5;
    string& metricName = (string &) "EUC";
public:
    virtual void execute();
    virtual string getDescription();
    virtual DefaultIO& getIO();
    explicit Command(DefaultIO& io);
    int getK();
    void setK(int k);
    string& getMetric();
    void setMetric(string& name);
};
#endif //SERVER_SIDE_COMMAND_H
