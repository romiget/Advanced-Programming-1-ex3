//
// Created by ido on 8/28/22.
//

using namespace std;
#include "ChangeParameters.h"
#include <iostream>

void ChangeParameters::execute() {
    string curr = io.read();
    cout <<
            "The current KNN parameters are: K = " + curr.substr(0, curr.find(',')) + ", distance metric = "
            + curr.substr(curr.find(',') + 1, curr.size() - curr.find(',') + 1))
            << endl;
    string input;
    cin >> input;
    bool flag = false;
    if (input.empty()) return;
    int newK;
    string newMet;
    try {
        if (input[1] == ' ' || stoi(input.substr(0, 2)) == 10) {
            newK = input[0] - '0';
            if (newK >= 10)
                flag = true;
        } else {
            cout << "Invalid value for K" << endl;
        }
        if (flag) {
            newMet = input.substr(3, 3);
        } else {
            newMet = input.substr(2, 3);
        }
        if (newMet != "EUC" && newMet != "MAN" && newMet != "CHE") {
            this->getIO().write("Invalid metric name");
        }
    } catch (exception &e) {
        this->getIO().write("Invalid input");
    }
    io.write(to_string(newK) + "," + newMet);
}

string ChangeParameters::getDescription() {
    return "algorithm settings";
}

ChangeParameters::ChangeParameters(DefaultIO &io) : Command(io){
}
