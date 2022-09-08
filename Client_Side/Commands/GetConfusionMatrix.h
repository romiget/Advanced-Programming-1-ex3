//
// Created by romrom4444 on 8/28/22.
//

// This class displays the server's algorithm's confusion matrix
// according to the current training file we sent it.
// The case where we don't have a training file yet is handled in CLI.cpp

#ifndef SERVER_SIDE_SHOWCONFUSIONMATRIX_H
#define SERVER_SIDE_SHOWCONFUSIONMATRIX_H

#include "Command.h"

class GetConfusionMatrix : public Command {
public:
    void execute() override;
    string getDescription() override;
    ~GetConfusionMatrix() override = default;
    explicit GetConfusionMatrix(DefaultIO* io);
};

#endif //SERVER_SIDE_SHOWCONFUSIONMATRIX_H
