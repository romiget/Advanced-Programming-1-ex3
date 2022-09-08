//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include <iostream>

void ChangeParameters::execute() {
    // gets the current parameters from the server
    string curr = io->read();
    cout <<
            "The current KNN parameters are: K = " + curr.substr(0, curr.find(',')) + ", distance metric = "
            + curr.substr(curr.find(',') + 1, curr.size() - curr.find(',') - 1)
            << endl;
    string line;
    int newK;
    string newMet;
    cin.ignore();
    getline(cin, line);
    if (line.empty()) {
        io->write("Invalid");
        return;
    }
    // splitting the user input by comma
    newK = stoi(line.substr(0, line.find(' ')));
    newMet = line.substr(line.find(' ') + 1, line.size() - line.find(' ') - 1);
    if (newK > 10) {
        cout << "Invalid input for K" << endl;
        io->write("Invalid");
    }
    else if (newMet != "EUC" && newMet != "MAN" && newMet != "CHE") {
        cout << "Invalid input for Metric" << endl;
        io->write("Invalid");
    }
    else
        io->write(to_string(newK) + "," + newMet);
}

string ChangeParameters::getDescription() {
    return "algorithm settings";
}

ChangeParameters::ChangeParameters(DefaultIO* io) : Command(io){
}
