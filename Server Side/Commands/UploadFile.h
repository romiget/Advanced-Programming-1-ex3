//
// Created by ido on 8/28/22.
//

// This commands receives a training file (classified)
// and an unclassified file from the client, and stores them
// separately for future use.

#ifndef SERVER_SIDE_UPLOADFILE_H
#define SERVER_SIDE_UPLOADFILE_H
#include "Command.h"

class UploadFile : public Command {
public:
    void execute(int& k, Metric** metric) override;
    explicit UploadFile(DefaultIO* io);
    ~UploadFile() override = default;
};
#endif //SERVER_SIDE_UPLOADFILE_H
