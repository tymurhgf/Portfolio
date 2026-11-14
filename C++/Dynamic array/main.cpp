#pragma once
#include "iostream"
#include "ctime"
#include "func.h"
using namespace std;

void main() {
	int size;
	cout << "Input array size: "; cin >> size;
	int* mas = NULL;
	mas = Create(mas, size);

	//«‡‚‰‡ÌÌˇ 1,2
	cout << "\nEnter an array from the keyboard: ";
	CinArray(mas, size);
	cout << "Array: ";
	—outArray(mas, size);

	RandArray(mas, size);
	cout << "Array: ";
	—outArray(mas, size);

	//«‡‚‰‡ÌÌˇ 3

	int value;
	cout << "\nEnter the number you want to remove from the array: "; cin >> value;
	mas = CompresArray(mas, size, value);
	cout << "Array: ";
	—outArray(mas, size);

	//«‡‚‰‡ÌÌˇ 4

	int block_size;
	cout << "\nInput block size: "; cin >> block_size;
	int* block = NULL;
	block = Create(block, block_size);
	RandArray(block, block_size);
	cout << "Block: ";
	—outArray(block, block_size);

	int pos;
	cout << "Input position to insert block: "; cin >> pos;
	mas = AddBlockToArray(mas, size, block, block_size, pos);
	cout << "Array: ";
	—outArray(mas, size);

	//«‡‚‰‡ÌÌˇ 5
	int del_pos, del_size;

	cout << "\nInput starting position for deletion: "; cin >> del_pos;
	cout << "Input number of elements to delete: "; cin >> del_size;
	mas = DeleteBlockFromArray(mas, size, del_size, del_pos);
	cout << "Array: ";
	—outArray(mas, size);

	delete[] mas;
	delete[] block;

	cin.get();
	cin.get();
}