//
// Created by romrom4444 on 8/28/22.
//

// This command classifies tells the server to classify
// the file we sent it. the case where there is no file yet
// is handled in CLI.cpp

#ifndef SERVER_SIDE_CLASSIFYFILE_H
#define SERVER_SIDE_CLASSIFYFILE_H

#include "Command.h"

class ClassifyFile : public Command {
public:
    void execute() override;
    string getDescription() override;
    ~ClassifyFile() override = default;
    explicit ClassifyFile(DefaultIO* io);
};

#endif //SERVER_SIDE_CLASSIFYFILE_H
