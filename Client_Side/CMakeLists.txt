cmake_minimum_required(VERSION 3.23)
project(Client_Side)

set(CMAKE_CXX_STANDARD 11)
add_executable(Client_Side main.cpp CLI.cpp CLI.h Commands/Command.cpp Commands/Command.h IO/DefaultIO.cpp IO/DefaultIO.h Commands/UploadFile.cpp Commands/UploadFile.h Commands/ChangeParameters.cpp Commands/ChangeParameters.h Commands/ClassifyFile.cpp Commands/ClassifyFile.h Commands/GetClassifications.cpp Commands/GetClassifications.h Commands/ReceiveClassificationFile.cpp Commands/ReceiveClassificationFile.h Commands/GetConfusionMatrix.cpp Commands/GetConfusionMatrix.h Commands/EndInteraction.cpp Commands/EndInteraction.h IO/DefaultIO.cpp IO/DefaultIO.h IO/StandardIO.cpp IO/StandardIO.h IO/SocketIO.cpp IO/SocketIO.h)