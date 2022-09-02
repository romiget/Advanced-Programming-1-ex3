//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_CLASSIFYFILE_H
#define SERVER_SIDE_CLASSIFYFILE_H

#include "Command.h"

class ClassifyFile : public Command {
public:
    void execute() override;
    string getDescription() override;
    explicit ClassifyFile(DefaultIO& io);
};

#endif //SERVER_SIDE_CLASSIFYFILE_H
