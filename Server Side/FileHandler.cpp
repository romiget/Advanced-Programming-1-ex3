//
// Created by ido on 7/29/22.
//
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "FileHandler.h"
#include "EuclideanMetric.h"
#include "ChebyshevMetric.h"
#include "ManhattanMetric.h"
#include "MeasurableList.h"
#include <utility>
#include <algorithm>

using namespace std;

vector<string> FileHandler::splitLine(const string& line, char delimiter) {
    vector<string> res;
    stringstream stringStream(line);
    string attribute;
    while (getline(stringStream, attribute, delimiter)) {
        res.push_back(attribute);
    }
    return res;
}

std::vector<Measurable> FileHandler::getMeasurables(const string& fileName) {
    fstream fs;
    fs.open(fileName);
    if (!fs) {
        throw exception();
    }
    vector<Measurable> measurables;
    string line;
    while (getline(fs, line)) {
        measurables.push_back(FileHandler::createMeasurableFromClassified(line));
    }
    fs.close();
    return measurables;
}

Measurable FileHandler::createMeasurableFromClassified(const string &line) {
    vector<string> measurable = splitLine(line, ',');
    Measurable result = Measurable();
    for (int i = 0; i < measurable.size() - 1; i++) {
        result.addAttribute(stod(measurable[i]));
    }
    result.setType(measurable[measurable.size() - 1]);
    return result;
}

Measurable FileHandler::createMeasurableFromUnclassified(string line) {
    line.append(",");
    return createMeasurableFromClassified(line);
}

void FileHandler::scan(const vector<Measurable> &measurables, fstream &fs, int k, Metric& func) {
    fstream scan("output.csv", ios::trunc);
    string line;
    while (getline(fs, line)) {
        Measurable measured = createMeasurableFromUnclassified(line);
        classify(measured, measurables, scan, k, func);
    }
    scan.close();
}

void FileHandler::classify(Measurable& measured, const vector<Measurable>& measurables, fstream& output, int k, Metric& func) {
    vector<Measurable> knn = MeasurableList::KNN((vector<struct Measurable> &) measurables,
            func, measured, k);
    measured.setType(FileHandler::knnCheck(knn));
    output << measured.getType() << endl;
}

string FileHandler::knnCheck(const vector<Measurable>& measurables) {
    vector<string> types;
    vector<int> counts;
    for (Measurable m : measurables) {
        auto it = find(types.begin(), types.end(), m.getType());
        if(it == types.end()) {
            types.push_back(m.getType());
            counts.push_back(1);
        }
        else {
            counts.at(it - types.begin())++;
        }
    }

    auto max = std::max_element(counts.begin(), counts.end());
    return types.at(max - counts.begin());

}
