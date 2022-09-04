//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include <iostream>

void ChangeParameters::execute() {
    string curr = io->read();
    cout <<
            "The current KNN parameters are: K = " + curr.substr(0, curr.find(',')) + ", distance metric = "
            + curr.substr(curr.find(',') + 1, curr.size() - curr.find(',') - 1)
            << endl;
    int newK;
    string newMet;
    cin >> newK;
    cin >> newMet;
    if (newK > 10)
        cout << "Invalid input for K" << endl;
    else if (newMet != "EUC" && newMet != "MAN" && newMet != "CHE")
        cout << "Invalid input for Metric" << endl;
    else
        io->write(to_string(newK) + "," + newMet);
}

string ChangeParameters::getDescription() {
    return "algorithm settings";
}

ChangeParameters::ChangeParameters(DefaultIO* io) : Command(io){
}
