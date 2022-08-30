//
// Created by romrom4444 on 8/28/22.
//

#ifndef SERVER_SIDE_SOCKETIO_H
#define SERVER_SIDE_SOCKETIO_H

#include "DefaultIO.h"

class SocketIO : public DefaultIO {
private:
    static int sock;
public:
    SocketIO(int sock);
    string& read() override;
    void write(string str) override;
    void end() override;
};

#endif //SERVER_SIDE_SOCKETIO_H
