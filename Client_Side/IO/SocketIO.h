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
    int server_sock;
public:
    SocketIO(int sock, int client_sock);
    string read() override;
    void write(string str) override;
    void end() const override;
};

#endif //ADVANCED_PROGRAMMING_1_EX3_SOCKETIO_H
