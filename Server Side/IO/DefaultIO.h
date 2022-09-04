//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_DEFAULTIO_H
#define SERVER_SIDE_DEFAULTIO_H
#include <string>

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;
    virtual void write(string str) = 0;
    virtual void end() = 0;
    virtual ~DefaultIO() = 0;
};
#endif //SERVER_SIDE_DEFAULTIO_H
