//
// Created by romrom4444 on 9/4/22.
//

#include "DefaultIO.h"
#include <string>

string DefaultIO::read() {
    //should've overridden that.
    throw exception();
}

void DefaultIO::write(string str) {
    //should've overridden that.
    throw exception();
}

void DefaultIO::end() const {
    // should've overridden that.
    throw exception();
}