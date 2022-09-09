//
// Created by ido on 7/22/22.
//

// This is a polymorphic class for the metric function. Its child classes are different defined metrics as tasked.

#ifndef ADVANCED_PROGRAMMING_1_METRIC_H
#define ADVANCED_PROGRAMMING_1_METRIC_H

#include <list>
#include <vector>
#include <string>

using namespace std;

class Metric {
public:
    // calculates the distance according to the class' formula
    virtual double metric(vector<double> l1, vector<double> l2) const;
    // returns the type of the metric
    virtual string getType();
};

#endif //ADVANCED_PROGRAMMING_1_METRIC_H
