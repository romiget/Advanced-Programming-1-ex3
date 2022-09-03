//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_SHOWCONFUSIONMATRIX_H
#define SERVER_SIDE_SHOWCONFUSIONMATRIX_H

#include "Command.h"
#include "../KNN Algorithm/Measurable.h"

class ShowConfusionMatrix : public Command {
    void createConfusionMatrix(const vector<Measurable>& realTypes, const vector<Measurable>& KNNTypes);
public:
    void execute() override;
    string getDescription() override;
    ~ShowConfusionMatrix() override = default;
    explicit ShowConfusionMatrix(DefaultIO& io);
};

#endif //SERVER_SIDE_SHOWCONFUSIONMATRIX_H
