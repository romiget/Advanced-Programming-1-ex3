//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_CHANGEPARAMETERS_H
#define SERVER_SIDE_CHANGEPARAMETERS_H
#include "Command.h"
using namespace std;

class ChangeParameters : public Command {
    int k = 5;
    string& metricName = (string &) "EUC";
public:
    void execute() override;
    int getK();
    void setK(int k);
    string& getMetric();
    void setMetric(string& name);
    explicit ChangeParameters(DefaultIO &io);
    string getDescription() override;
};
#endif //SERVER_SIDE_CHANGEPARAMETERS_H
