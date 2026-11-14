#pragma once
#include "iostream"
#include "ctime"
#include "myArray.h"
using namespace std;

void main() {
	//Завдання 1
	cout << "\n";
	int a = 12, b = 2, c = 9;
	cout << "a = " << a << " b = " << b << " c = " << c <<"\n";
	int* ap = &a, *bp = &b, *cp = &c;

	cout << Dob(ap, bp, cp);
	cout << "\n" << SerArfm(ap, bp, cp);
	cout << "\n" << Min(ap, bp, cp);

	//Завдання 2
	const int size = 15;
	int mas[size];

	cout << "\n";
	RandArr(mas, size);
	PrArr(mas, size);

	cout << "\n";
	ZvArr(mas, size);
	PrArr(mas, size);

	cout << "\nSum: " << SumElMas(mas, size);

	//Завдання 3
	cout << "\n";
	double mas2[size] = { 1.5, 3.7, 8.9, 4.7, 1.1, 4.5, 9.0, 8.4, 6.9, 2.5, 3.5, 4.6, 3.5, 2.7, 7.1 };
	PrArr(mas2, size);
	int min = 0, max = 0;

	MinMax(mas2, size, &min, &max);
	PrArr(mas2, size);

	//Завдання 4
	cout << "\n";
	ZminPolMas(mas2, size);
	PrArr(mas2, size);

	//Завдання 5
	cout << "\n";
	PrArr(mas, size);
	ParToNeparn(mas, size);
	PrArr(mas, size);

	cin.get();
	cin.get();
}