//
// Created by romrom4444 on 8/28/22.
//

// This command classifies the current unclassified file
// according to the current training file.

#ifndef SERVER_SIDE_CLASSIFYFILE_H
#define SERVER_SIDE_CLASSIFYFILE_H

#include "Command.h"

class ClassifyFile : public Command {
public:
    void execute(int& k, Metric** metric) override;
    ~ClassifyFile() override = default;
    explicit ClassifyFile(DefaultIO* io);
};

#endif //SERVER_SIDE_CLASSIFYFILE_H
