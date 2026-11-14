#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
	CarManage cm;
	int choice;

	do {
		cout << "Menu:\n"
			<< "1.Add a car\n"
			<< "2.Show all cars\n"
			<< "3.Sort cars\n"
			<< "4.Search cars\n"
			<< "0.Exit\n"
			<< "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cm.addCar();
			break;
		case 2:
			cm.showAll();
			break;
		case 3:
			cm.sortCars();
			break;
		case 4:
			cm.searchCars();
			break;
		case 0:
			break;
		default:
			cout << "Incorrect choice.\n";
		}
		cout << "\n";
	} while (choice != 0);

	cin.get();
	cin.get();
}
