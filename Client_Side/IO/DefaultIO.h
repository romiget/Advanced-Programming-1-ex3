//
// Created by romrom4444 on 9/4/22.
//

// This is a polymorphic class for input/output interaction.

#ifndef ADVANCED_PROGRAMMING_1_EX3_DEFAULTIO_H
#define ADVANCED_PROGRAMMING_1_EX3_DEFAULTIO_H

#include <string>

using namespace std;

class DefaultIO {
public:
    // reads information from the other end
    virtual string read() = 0;
    // writes information to the other end
    virtual void write(string str) = 0;
    // closes the interaction
    virtual void end() const = 0;
    virtual ~DefaultIO() = 0;
};

#endif //ADVANCED_PROGRAMMING_1_EX3_DEFAULTIO_H
