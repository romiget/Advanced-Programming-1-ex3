//
// Created by romrom4444 on 8/28/22.
//

// This command displays the classifications of the unclassified file
// to the client.

#ifndef SERVER_SIDE_SHOWCLASSIFICATIONS_H
#define SERVER_SIDE_SHOWCLASSIFICATIONS_H

#include "Command.h"

class ShowClassifications : public Command {
public:
    void execute(int& k, Metric** metric) override;
    ~ShowClassifications() override = default;
    explicit ShowClassifications(DefaultIO* io);
};

#endif //SERVER_SIDE_SHOWCLASSIFICATIONS_H
