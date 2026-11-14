#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

class Train {
private:
    string numb;
    string depSt;
    string depT;
    string destSt;
    string arrTime;
public:
    Train() : numb(""), depSt(""), depT(""), destSt(""), arrTime("") {}
	Train(string num) : numb(num), depSt(""), depT(""), destSt(""), arrTime("") {}
	Train(string num, string depSt) : numb(num), depSt(depSt), depT(""), destSt(""), arrTime("") {}
    Train(string num, string depSt, string depTime) : numb(num), depSt(depSt), depT(depTime), destSt(""), arrTime("") {}
    Train(string num, string depSt, string depTime, string destSt): numb(num), depSt(depSt), depT(depTime), destSt(destSt), arrTime("") {}
    Train(string num, string depSt, string depTime, string destSt, string arrTime): numb(num), depSt(depSt), depT(depTime), destSt(destSt), arrTime(arrTime) {}

    string getNumb() const { return numb; }
    string getDepStation() const { return depSt; }
    string getDepTime() const { return depT; }
    string getDestnStation() const { return destSt; }
    string getArrTime() const { return arrTime; }

    void print() const {
        cout << "Number: " << numb<< "\nDeparture: " << depSt << " (" << depT << ")" << "\nDestination: " << destSt << " (" << arrTime << ")" << endl;
    }
};

void addTrain(list<Train>& trains) {
    string num, depSt, depTime, destSt, arrTime;

    cout << "Enter train number: "; cin >> num;
    for (const auto& train : trains) {
        if (train.getNumb() == num) {
            cout << "\nA train with number " << num << " already exists!\n";
            return;
        }
    }
    cout << "Enter departure station: "; cin >> depSt;
    cout << "Enter departure time: "; cin >> depTime;
    cout << "Enter destination station: "; cin >> destSt;
    cout << "Enter arrival time: "; cin >> arrTime;

    trains.push_back(Train(num, depSt, depTime, destSt, arrTime));
	cout << "\nAdded successfully.\n";
}

void displayAll(const list<Train>& trains) {
    if (trains.empty()) {
        cout << "List is empty.\n";
        return;
    }
    cout << "\nList of all trains\n";
    for (auto it = trains.begin(); it != trains.end(); it++) {
        it->print();
        cout << "\n";
    }
}

void TrainByNumb(const list<Train>& trains) {
    if (trains.empty()) {
        cout << "List is empty.\n";
        return;
    }
    string num;
    cout << "Enter number to find: "; cin >> num;
    bool found = false;
    for (auto it = trains.begin(); it != trains.end(); it++) {
        if (it->getNumb() == num) {
            cout << "\n";
            it->print();
            found = true;
        }
    }
    if (!found) {
        cout << "Train with number " << num << " not found.\n";
    }
}

void TrainsByDest(const list<Train>& trains) {
    if (trains.empty()) {
        cout << "List is empty.\n";
        return;
    }
    string dest;
    cout << "Enter destination station to search: "; cin >> dest;
    bool found = false;
    for (auto it = trains.begin(); it != trains.end(); it++) {
        if (it->getDestnStation() == dest) {
            cout << "\n";
            it->print();
            found = true;
        }
    }
    if (!found) {
        cout << "Trains to station " << dest << " not found.\n";
    }
}

void deleteTrain(list<Train>& trains) {
    if (trains.empty()) {
        cout << "List is empty.\n";
        return;
    }
    string num;
    cout << "Enter number to delete: ";
    cin >> num;
    bool found = false;
	auto it = trains.begin();
    while (it != trains.end()) {
        if (it->getNumb() == num) {
            cout << "\n";
            it = trains.erase(it);
            found = true;
            cout << "Successfully deleted.\n";
        }
        else {
            ++it;
        }
    }
    if (!found) {
        cout << "Train with number " << num << " not found.\n";
    }
}
