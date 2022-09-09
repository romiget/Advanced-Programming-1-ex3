//
// Created by romrom4444 on 9/4/22.
//

// Standard input/output interaction. Not viable for server-client interaction.

#ifndef ADVANCED_PROGRAMMING_1_EX3_STANDARDIO_H
#define ADVANCED_PROGRAMMING_1_EX3_STANDARDIO_H

#include "DefaultIO.h"
#include <string>

class StandardIO : public DefaultIO {
public:
    string read() override;
    void write(string str) override;
    void end() const override;
    ~StandardIO() override = default;
};

#endif //ADVANCED_PROGRAMMING_1_EX3_STANDARDIO_H
