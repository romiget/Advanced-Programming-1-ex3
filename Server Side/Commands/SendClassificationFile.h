//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_SENDCLASSIFICATIONFILE_H
#define SERVER_SIDE_SENDCLASSIFICATIONFILE_H

#include "Command.h"

class SendClassificationFile : public Command {
public:
    void execute(int& k, Metric** metric) override;
    ~SendClassificationFile() override = default;
    explicit SendClassificationFile(DefaultIO* io);
};

#endif //SERVER_SIDE_SENDCLASSIFICATIONFILE_H
