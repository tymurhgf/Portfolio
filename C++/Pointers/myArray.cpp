#pragma once
#include "iostream"
#include "ctime"
#include "myArray.h"
using namespace std;

int Dob(int* a, int* b, int* c) {
	return *a * *b * *c;
}

double SerArfm(int* a, int* b, int* c) {
	return ((*a + *b + *c) / 3.);
}

int Min(int* a, int* b, int* c) {
	int min = *a;
	if (*b < min){
		min = *b;
	}
	if (*c < min) {
		min = *c;
	}
	return min;
}




void RandArr(int* mas, int size) {
	srand(time(0));
	for (int i = 0; i < size; ++i)
		*(mas + i) = rand() % 10;
}

void ZvArr(int* mas, int size) {
	int temp;
	for (int i = 0; i < size / 2; ++i) {
		temp = *(mas + i);
		*(mas + i) = *(mas + size - 1 - i);
		*(mas + size - 1 - i) = temp;
	}
}

int SumElMas(int* mas, int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += *(mas+i);
	}
	return sum;
}



void MinMax(double* mas, int size, int *min, int *max) {
	*min = 0;
	*max = 0;
	for (int i = 0; i < size; ++i) {
		if (*(mas + i) < *(mas + *min)) {
			*min = i;
		}
		if (*(mas + i) > *(mas + *max)) {
			*max = i;
		}
	}
	double temp = *(mas + *min);
	*(mas + *min) = *(mas + *max);
	*(mas + *max) = temp;
}



void PrArr(double* mas, int size) {
	cout << "\n";
	for (int i = 0; i < size; ++i)
		cout << *(mas + i) << " ";
	cout << " ";
}
void PrArr(int* mas, int size) {
	cout << "\n";
	for (int i = 0; i < size; ++i)
		cout << *(mas + i) << " ";
}



void ZminPolMas(double* mas, int size) {
	int Pol = size / 2;
	double temp;
	double* DrPol = mas + (size - Pol);

	for (int i = 0; i < Pol; i++) {
		temp = *(mas + i);
		*(mas + i) = *(DrPol + i);
		*(DrPol + i) = temp;
	}
}



void ParToNeparn(int* mas, int size) {
	int temp;
	for (int i = 0; i < size - 1; i += 2) {
		temp = *(mas + i);
		*(mas + i) = *(mas + i + 1);
		*(mas + i + 1) = temp;
	}
}