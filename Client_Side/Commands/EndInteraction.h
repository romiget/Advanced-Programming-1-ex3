//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_ENDINTERACTION_H
#define SERVER_SIDE_ENDINTERACTION_H

#include "Command.h"

class EndInteraction : public Command {
public:
    void execute() override;
    string getDescription() override;
    ~EndInteraction() override = default;
    explicit EndInteraction() = default;
};

#endif //SERVER_SIDE_ENDINTERACTION_H
