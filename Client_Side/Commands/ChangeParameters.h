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
    explicit ChangeParameters() = default;
    ~ChangeParameters() override = default;
    string getDescription() override;
};
#endif //SERVER_SIDE_CHANGEPARAMETERS_H
