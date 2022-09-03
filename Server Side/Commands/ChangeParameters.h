//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_CHANGEPARAMETERS_H
#define SERVER_SIDE_CHANGEPARAMETERS_H
#include "Command.h"
using namespace std;

class ChangeParameters : public Command {
public:
    void execute() override;
    explicit ChangeParameters(DefaultIO &io);
    ~ChangeParameters() override = default;
    string getDescription() override;
};
#endif //SERVER_SIDE_CHANGEPARAMETERS_H
