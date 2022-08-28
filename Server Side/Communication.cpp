//
// Created by romrom4444 on 8/23/22.
//

#include "Communication.h"
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
#include "ChebyshevMetric.h"
#include "ManhattanMetric.h"

using namespace std;

void Communication::getUnclassifiedFileFromClient(const string& pathName) {
    unclassified = pathName;
}

void Communication::getClassifiedFileFromClient(const string& pathName) {
    fstream fs(data, ios::trunc);
    fs.open(data);
    string line;
    fstream received(pathName, ios::app);
    received.open(pathName);
    while(getline(received, line)) {
        fs.write(line.c_str(), line.size());
    }
}

void Communication::showCurrentParameters() {
    cout << "The current KNN parameters are: K = " << k << ", distance metric = " << func.getType() << endl;
}

void Communication::changeCurrentParameters(int val, string &metric) {
    if (val >= 1 && val <= 10) {
        this->k = val;
    } else {
        cout << "invalid value for k" << endl;
    }
    if (metric == "EUC") this->func = EuclideanMetric();
    else if (metric == "CHE") this->func = ChebyshevMetric();
    else if (metric == "MAN") this->func = ManhattanMetric();
    else cout << "no such metric" << endl;
}

void Communication::classifyCurrentData() {
    vector<Measurable> measurables = FileHandler::getMeasurables(data);
    fstream fs(unclassified, ios::app);
    FileHandler::scan(measurables, fs, k, func);
}

void Communication::printClassifications() {
    fstream fs = fstream("output.csv", ios::app);
    string line;
    int row = 1;
    while(getline(fs, line)) {
        cout << row << "\t" << line << endl;
        row++;
    }
    cout << "Done." << endl;
    fs.close();
}
