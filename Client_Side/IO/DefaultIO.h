//
// Created by romrom4444 on 9/4/22.
//

#ifndef ADVANCED_PROGRAMMING_1_EX3_DEFAULTIO_H
#define ADVANCED_PROGRAMMING_1_EX3_DEFAULTIO_H

#include <string>

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;
    virtual void write(string str) = 0;
    virtual void end() const = 0;
    virtual ~DefaultIO() = 0;
};

#endif //ADVANCED_PROGRAMMING_1_EX3_DEFAULTIO_H
