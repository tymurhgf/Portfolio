#pragma once
#include "iostream"
#include "func.h"
using namespace std;

void main() {
    double x, y, z;

    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    cout << "Cube of first number: " << CUBE(x) << "\n";
    cout << "Greater of first two: " << MAX_OF_TWO(x, y) << "\n";
	cout << "Sum of three numbers: " << SUM_OF_THREE(x, y, z) << "\n";
    cout << "Sign changed: " << NEGATE(x) << "\n";
	cout << "Smallest of three numbers: " << MIN_OF_THREE(x, y, z) << "\n";

    cin.get();
    cin.get();
}