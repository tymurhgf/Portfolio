#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
	srand(time(0));
	int count = 3; 

	shared_ptr<Fraction[]> fractions(new Fraction[count]);

	for (int i = 0; i < count; ++i) {
		cout << "Fraction [" << i << "]: ";
		fractions[i].show();
	}
	cout << "\n";

	fractions[0].setNumerator(5);
	fractions[0].setEnumerator(2);

	fractions[1].setNumerator(7);
	fractions[1].setEnumerator(3);

	cout << "After modification: \n";
	for (int i = 0; i < count; ++i) {
		cout << "Fraction [" << i << "]: ";
		fractions[i].show();
	}
	cout << "\n";

	cout << "0 + 1 = " << (fractions[0] + fractions[1]) << endl;
	cout << "0 * 1 = " << (fractions[0] * fractions[1]) << endl;
	cout << "\n";

	SaveToFile(fractions[0]);

	Fraction frFromFile;
	LoadFromFile(frFromFile);
	cout << "Loaded 0 from file: ";
	frFromFile.show();
	cout << "\n";

}