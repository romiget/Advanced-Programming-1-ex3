//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_SOCKETIO_H
#define SERVER_SIDE_SOCKETIO_H

#include "DefaultIO.h"

class SocketIO : public DefaultIO {
private:
    int sock;
    int client_sock;
public:
    SocketIO(int sock, int client_sock);
    string read() override;
    void write(string str) override;
    void end() override;
    ~SocketIO() override = default;
};

#endif //SERVER_SIDE_SOCKETIO_H
