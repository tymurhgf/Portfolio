#pragma once
#include "iostream"
#include "ctime"
#include "func.h"
using namespace std;

int* Create(int* mas, int size)
{
	mas = new int[size];
	return mas;
}


void CinArray(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> mas[i]; 
	}
}
void RandArray(int* mas, int size)
{
	srand(time(0));
	for (int i = 0; i < size; ++i)
		mas[i] = rand() % 10;
}


void ÑoutArray(int* mas, int size)
{
	for (int i = 0; i < size; ++i)
		cout << mas[i] << " ";
	cout << "\n";
}

int* CompresArray(int* mas, int& size, int val) {
	int* temp = NULL;
	int k = 0;

	for (int i = 0; i < size; ++i) {
		if (mas[i] == val) {
			k++;
		}
	}

	int new_size = size - k;
	temp = Create(temp, size - k);

	int tempInd = 0;
	for (int i = 0; i < size; ++i) {
		if (mas[i] != val) {
			temp[tempInd] = mas[i];
			tempInd++;
		}
	}

	size = new_size;
	delete[] mas;

	return temp;
}

int* AddBlockToArray(int* mas, int& size, int* block, int size_block, int pos) {
	int* temp = NULL;
	int new_size = size + size_block;
	temp = Create(temp, new_size);

	for (int i = 0; i < pos; ++i) {
		temp[i] = mas[i];
	}

	for (int i = 0; i < size_block; ++i) {
		temp[pos + i] = block[i];
	}

	for (int i = pos; i < size; ++i) {
		temp[i + size_block] = mas[i];
	}

	size = new_size;
	delete[] mas;

	return temp;
}

int* DeleteBlockFromArray(int* mas, int& size, int size_block, int pos) {
	int* temp = NULL;
	int new_size = size - size_block;
	temp = Create(temp, new_size);

	for (int i = 0; i < pos; ++i) {
		temp[i] = mas[i];
	}

	for (int i = pos; i < new_size; ++i) {
		temp[i] = mas[i + size_block];
	}

	delete[] mas;
	size = new_size;
	return temp;
}