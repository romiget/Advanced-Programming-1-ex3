//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_SENDCLASSIFICATIONFILE_H
#define SERVER_SIDE_SENDCLASSIFICATIONFILE_H

#include "Command.h"

class ReceiveClassificationFile : public Command {
public:
    void execute() override;
    string getDescription() override;
    ~ReceiveClassificationFile() override = default;
    explicit ReceiveClassificationFile(DefaultIO* io);
};

#endif //SERVER_SIDE_SENDCLASSIFICATIONFILE_H
