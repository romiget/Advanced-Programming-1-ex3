cmake_minimum_required(VERSION 3.22)
project(Server_Side)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server_Side main.cpp "KNN Algorithm/Measurable.cpp" "KNN Algorithm/Measurable.h" Metrics/Metric.cpp Metrics/Metric.h Metrics/EuclideanMetric.cpp Metrics/EuclideanMetric.h Metrics/ManhattanMetric.cpp Metrics/ManhattanMetric.h Metrics/ChebyshevMetric.cpp Metrics/ChebyshevMetric.h "KNN Algorithm/MeasurableList.cpp" "KNN Algorithm/MeasurableList.h" "KNN Algorithm/FileHandler.cpp" "KNN Algorithm/FileHandler.h" Metrics/ChebyshevMetric.cpp Commands/Command.cpp Commands/Command.h IO/DefaultIO.cpp IO/DefaultIO.h Commands/UploadFile.cpp Commands/UploadFile.h Commands/ChangeParameters.cpp Commands/ChangeParameters.h CLI.cpp CLI.h)
