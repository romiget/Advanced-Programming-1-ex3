//
// Created by ido on 8/28/22.
//

#ifndef SERVER_SIDE_UPLOADFILE_H
#define SERVER_SIDE_UPLOADFILE_H
#include "Command.h"

class UploadFile : public Command {
public:
    void execute() override;
};
#endif //SERVER_SIDE_UPLOADFILE_H
