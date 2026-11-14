#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
	list<Train> trains;
	int choice;

	do {
		cout << "Menu:\n";
		cout << "1.Add train\n";
		cout << "2.Display all trains\n";
		cout << "3.Find train by number\n";
		cout << "4.Find trains by destination station\n";
		cout << "5.Delete train by number\n";
		cout << "6.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addTrain(trains);
			break;
		case 2:
			displayAll(trains);
			break;
		case 3:
			TrainByNumb(trains);
			break;
		case 4:
			TrainsByDest(trains);
			break;
		case 5:
			deleteTrain(trains);
			break;
		case 6:
			break;
		default:
			cout << "Invalid choice.\n";
			break;
		}
		cout << "\n";
	} while (choice != 6 && choice > 0 && choice < 7);

	cin.get();
	cin.get();
}