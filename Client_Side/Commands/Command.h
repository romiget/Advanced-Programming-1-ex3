//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_COMMAND_H
#define SERVER_SIDE_COMMAND_H
#include <string>
#include "../IO/DefaultIO.h"

using namespace std;

class Command {
private:
    string description;
protected:
    DefaultIO& io;
public:
    virtual void execute() = 0;
    virtual string getDescription();
    virtual DefaultIO& getIO();
    explicit Command(DefaultIO &io);
    virtual ~Command() = default;
};
#endif //SERVER_SIDE_COMMAND_H
