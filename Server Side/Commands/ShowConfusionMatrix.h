//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_SHOWCONFUSIONMATRIX_H
#define SERVER_SIDE_SHOWCONFUSIONMATRIX_H

#include "Command.h"

class ShowConfusionMatrix : public Command {
public:
    void execute() override;
    string getDescription() override;
    DefaultIO& getIO() override;
    explicit ShowConfusionMatrix(DefaultIO& io);
};

#endif //SERVER_SIDE_SHOWCONFUSIONMATRIX_H
