//
// Created by romrom4444 on 8/23/22.
//

#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "FileHandler.h"
#include <exception>
#include "EuclideanMetric.h"

#ifndef SERVER_SIDE_COMMUNICATION_H
#define SERVER_SIDE_COMMUNICATION_H

using namespace std;
class Communication {
private:
    string& unclassified;
    string& data;
    int k;
    Metric func;
    void getUnclassifiedFileFromClient(const string& pathName);
    void getClassifiedFileFromClient(const string& pathName);
    void showCurrentParameters();
    void changeCurrentParameters(int k, string& metric);
    void classifyCurrentData();
    void printClassifications();
    void sendClassificationsFile();
    void showConfusionMatrix();
    void closeInteraction();
public:
    Communication(int sock, int client_sock);
    void loop();
};

#endif //SERVER_SIDE_COMMUNICATION_H
