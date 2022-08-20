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

std::vector<Measurable> FileHandler::getFlowers(const string& fileName) {
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
    fstream scan;
    scan.open("euclidean_output.csv", ios::out);
    string line;
    while (getline(fs, line)) {
        Measurable measured = createMeasurableFromUnclassified(line);
        classify(measured, measurables, scan, k, func);
    }
    scan.close();
}

void FileHandler::classify(Measurable& measured, const vector<Measurable>& measurables, fstream& euclid, int k, Metric& func) {
    vector<Measurable> knn = MeasurableList::KNN((vector<struct Measurable> &) measurables,
            func, measured, k);
    measured.setType(FileHandler::knnCheck(knn));
    //euclid << measured.getType() << endl;
}

string FileHandler::knnCheck(const vector<Measurable>& measurables) {
    pair<int, string> setosa = {0, "Iris-setosa"};
    pair<int, string> versicolor = {0, "Iris-versicolor"};
    pair<int, string> virginica = {0, "Iris-virginica"};
    for (auto & measurable : measurables) {
        if (measurable.getType() == "Iris-setosa")
            setosa.first++;
        else if (measurable.getType() == "Iris-versicolor")
            versicolor.first++;
        else if (measurable.getType() == "Iris-virginica")
            virginica.first++;
    }
    pair<int, string> maximum;
    if (setosa > versicolor)
        maximum = setosa;
    else
        maximum = versicolor;
    if (virginica > maximum)
        maximum = virginica;
    return maximum.second;
}
