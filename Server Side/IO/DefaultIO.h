//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_DEFAULTIO_H
#define SERVER_SIDE_DEFAULTIO_H
#include <string>

using namespace std;

class DefaultIO {
public:
    virtual string read();
    virtual void write(string str);
    virtual void end();
};
#endif //SERVER_SIDE_DEFAULTIO_H
