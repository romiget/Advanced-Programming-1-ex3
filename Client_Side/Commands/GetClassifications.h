//
// Created by romrom4444 on 8/28/22.
//

// This command receives the classification information from the server
// and displays it on screen. The case where we have yet to classify the file
// is handled in CLI.cpp

#ifndef SERVER_SIDE_SHOWCLASSIFICATIONS_H
#define SERVER_SIDE_SHOWCLASSIFICATIONS_H

#include "Command.h"

class GetClassifications : public Command {
public:
    void execute() override;
    string getDescription() override;
    ~GetClassifications() override = default;
    explicit GetClassifications(DefaultIO* io);
};

#endif //SERVER_SIDE_SHOWCLASSIFICATIONS_H
