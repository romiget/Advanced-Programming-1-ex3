//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_STANDARDIO_H
#define SERVER_SIDE_STANDARDIO_H

#include "DefaultIO.h"

class StandardIO : public DefaultIO {
public:
    string read() override;
    void write(string str) override;
    void end() override;
};

#endif //SERVER_SIDE_STANDARDIO_H
