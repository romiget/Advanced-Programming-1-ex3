//
// Created by romrom4444 on 9/4/22.
//

#include <string>
#include "DefaultIO.h"

#ifndef ADVANCED_PROGRAMMING_1_EX3_SOCKETIO_H
#define ADVANCED_PROGRAMMING_1_EX3_SOCKETIO_H

class SocketIO : public DefaultIO {
private:
    int sock;
public:
    SocketIO(int sock);
    string read() override;
    void write(string str) override;
    void end() const override;
    ~SocketIO() override = default;
};

#endif //ADVANCED_PROGRAMMING_1_EX3_SOCKETIO_H
