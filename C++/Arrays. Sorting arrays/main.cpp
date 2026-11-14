#include "iostream"
#include "ctime"
using namespace std;

#define size 20

void main() {
	// Завдання 1
	srand(time(0));

	int x = -50;
	int y = 50;
	int arr1[size], arr2[size], arr3[size], arr4[size];

	for (int i = 0; i < size; i++)
	{
		arr1[i] = rand() % (x - y) + x;
		arr2[i] = rand() % (x - y) + x;
		arr3[i] = rand() % (x - y) + x;
		arr4[i] = rand() % (x - y) + x;
	}

	cout << "Array 1: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << "\nArray 2: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << "\nArray 3: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << "\nArray 4: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr4[i] << " ";
	}

	// Завдання 2
	int temp;
	for (int i = 0; i < size - 1; i++) {
		int max = i;
		for (int j = i + 1; j < size; j++) {
			if (arr1[j] > arr1[max]) {
				max = j;
			}
		}
	temp = arr1[i];
	arr1[i] = arr1[max];
	arr1[max] = temp;
	}
	cout << "\nSorted array 1: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr1[i] << " ";
	}

	// Завдання 3
	int border = 0;

	for (int i = 0; i < size; i++) {
		if (arr2[i] < 0) {
			int temp = arr2[i];
			arr2[i] = arr2[border];
			arr2[border] = temp;
			border++;
		}
	}

	for (int i = 0; i < border - 1; i++) {
		int min = i;
		for (int j = i + 1; j < border; j++) {
			if (arr2[j] < arr2[min]) { 
				min = j;
			}
		}
		int temp = arr2[i];
		arr2[i] = arr2[min];
		arr2[min] = temp;
	}

	for (int i = border; i < size - 1; i++) {
		int max = i;
		for (int j = i + 1; j < size; j++) {
			if (arr2[j] > arr2[max]) { 
				max = j;
			}
		}
		int temp = arr2[i];
		arr2[i] = arr2[max];
		arr2[max] = temp;
	}

	cout << "\nSorted array 2: ";
	for (int i = 0; i < size; i++) {
		cout << arr2[i] << " ";
	}

	// Завдання 4

	for (int i = 0; i < size; i += 2) {
		int min = i;
		for (int j = i + 2; j < size; j += 2) { 
			if (arr3[j] < arr3[min]) {
				min = j;
			}
		}
		int temp = arr3[i];
		arr3[i] = arr3[min];
		arr3[min] = temp;
	}

	for (int i = 1; i < size; i += 2) {
		int max = i;
		for (int j = i + 2; j < size; j += 2) { 
			if (arr3[j] > arr3[max]) { 
				max = j;
			}
		}
		int temp = arr3[i];
		arr3[i] = arr3[max];
		arr3[max] = temp;
	}

	cout << "\nSorted array 3: ";
	for (int i = 0; i < size; i++) {
		cout << arr3[i] << " ";
	}

	// Завдання 5

	for (int i = 0; i < 10 - 1; i++) {
		int min = i;
		for (int j = i + 1; j < 10; j++) { 
			if (arr4[j] < arr4[min]) { 
				min = j;
			}
		}
		int temp = arr4[i];
		arr4[i] = arr4[min];
		arr4[min] = temp;
	}

	for (int i = 10; i < size - 1; i++) { 
		int max = i;
		for (int j = i + 1; j < size; j++) { 
			if (arr4[j] > arr4[max]) { 
				max = j;
			}
		}
		int temp = arr4[i];
		arr4[i] = arr4[max];
		arr4[max] = temp;
	}

	cout << "\nSorted array 4: ";
	for (int i = 0; i < size; i++) {
		cout << arr4[i] << " ";
	}


	cin.get();
	cin.get();
}