//
// Created by romrom4444 on 8/28/22.
//

// This command closes the interaction from the client that called the command.

#ifndef SERVER_SIDE_ENDINTERACTION_H
#define SERVER_SIDE_ENDINTERACTION_H

#include "Command.h"

class EndInteraction : public Command {
public:
    void execute(int& k, Metric** metric) override;
    ~EndInteraction() override = default;
    explicit EndInteraction(DefaultIO* io);
};

#endif //SERVER_SIDE_ENDINTERACTION_H
