//
// Created by ido on 8/28/22.
//

// This is a polymorphic class for input/output interaction.

#ifndef SERVER_SIDE_DEFAULTIO_H
#define SERVER_SIDE_DEFAULTIO_H
#include <string>

using namespace std;

class DefaultIO {
public:
    // reads information from the other end
    virtual string read() = 0;
    // writes information to the other end
    virtual void write(string str) = 0;
    // closes the interaction
    virtual void end() = 0;
    virtual ~DefaultIO() = 0;
};
#endif //SERVER_SIDE_DEFAULTIO_H
