//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_SHOWCLASSIFICATIONS_H
#define SERVER_SIDE_SHOWCLASSIFICATIONS_H

#include "Command.h"

class GetClassifications : public Command {
public:
    void execute() override;
    string getDescription() override;
    ~GetClassifications() override = default;
    explicit GetClassifications(DefaultIO& io);
};

#endif //SERVER_SIDE_SHOWCLASSIFICATIONS_H
