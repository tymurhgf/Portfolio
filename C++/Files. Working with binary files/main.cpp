#pragma once
#include "iostream"
#include "func.h"
using namespace std;

void main()
{
	char choise = ' ';
	int IChoise;
	int size = 0;
	STUDENT* zhurn = new STUDENT[size];
	char s[20]; // s - ל³סעטעü רכÿץ המ פאיכף

	cout << "Journal Starostu\n";
	cout << "1. Load a journal\n";
	cout << "2. Create a new journal\n";
	cout << "Your choice: "; cin >> IChoise;
	if (IChoise == 1) {
		cout << "Enter file name to load: "; cin >> s;
		strcat_s(s, 20, ".dat");

		zhurn = LoadFromFile(zhurn, size, s);
	}
	else if (IChoise == 2) {
		cout << "Enter name for the new journal: "; cin >> s;
		strcat_s(s, 20, ".dat");
		size = 0;
	}

	STUDENT newSt; int delIndex;
	int size2 = 0; STUDENT* sortBOnAutmn = NULL;
	int size3 = 0; STUDENT* JAft25 = NULL;
	while (choise != '0')
	{
		cout << "\n1. Show all students\n"
			<< "2. Add a student\n"
			<< "3. Delete a student\n"
			<< "4. Show students born in autumn\n"
			<< "5. Show students enrolled after August 25\n"
			<< "6. Save changes to file\n"
			<< "0. Exit the program\n"
			<< "Choose an action: ";
		cin >> choise;

		switch (choise)
		{
		case '1': {
			showStudent(zhurn, size);
			break;
		}
		case '2': {
			newSt = inputStudent();
			zhurn = addStudent(zhurn, size, newSt);
			break;
		}
		case '3': {
			if (size == 0) {
				cout << "Journal is empty\n";
				break;
			}
			showStudent(zhurn, size);
			cout << "Enter the number of student to delete: "; cin >> delIndex;
			zhurn = removeStudent(zhurn, size, delIndex - 1);
			break;
		}
		case '4': {
			sortBOnAutmn = bOnAutmn(zhurn, size, sortBOnAutmn, size2);
			cout << "Students born in autumn:\n";
			showStudent(sortBOnAutmn, size2);
			delete[] sortBOnAutmn;
			break;
		}
		case '5': {
			JAft25 = JoinAfter25(zhurn, size, JAft25, size3);
			cout << "Students enrolled after August 25:\n";
			showStudent(JAft25, size3);
			delete[] JAft25;
			break;
		}
		case '6': {
			saveToFile(s, zhurn, size);
			break;
		}
		case '0': {
			cout << "Exiting the program\n";
			break;
		}
		}
	}
delete[] zhurn;
}
