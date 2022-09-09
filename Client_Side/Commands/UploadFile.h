//
// Created by ido on 8/28/22.
//

// This commands sends a training file (classified)
// and an unclassified file to the server for later use.

#ifndef SERVER_SIDE_UPLOADFILE_H
#define SERVER_SIDE_UPLOADFILE_H
#include "Command.h"

class UploadFile : public Command {
public:
    void execute() override;
    explicit UploadFile(DefaultIO* io);
    ~UploadFile() override = default;
    string getDescription() override;
};
#endif //SERVER_SIDE_UPLOADFILE_H
