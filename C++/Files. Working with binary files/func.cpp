#pragma once
#include <iostream>
#include "func.h"
using namespace std;

STUDENT* LoadFromFile(STUDENT* a, int& size, const char* s)
{
	delete[] a;
	FILE* g;
	fopen_s(&g, "size.dat", "rb");
	fread(&size, sizeof(int), 1, g); //В сайз записуємо з файлу
	if (size <= 0) {
		fclose(g);
		size = 0;
		return nullptr;
	}
	fclose(g);

	STUDENT* temp = new STUDENT[size];
	FILE* f;
	fopen_s(&f, s, "rb");
	STUDENT dat;
	for (int i = 0; i < size; ++i)
	{
		fread(&dat, sizeof(STUDENT), 1, f);
		temp[i] = dat;
	}
	fclose(f);
	return temp;
}

void showStudent(STUDENT* st, int size)
{
	for (int i = 0; i < size; ++i)
		cout << "Student number: " << i + 1 << "\n\n"
		<< st[i].pi.name << " " << st[i].pi.prisv
		<< "\nAdress: Country: " << st[i].adr.countr << "| Region: " << st[i].adr.obl << "| City: " << st[i].adr.city << "| Street: " << st[i].adr.strt << "| House: " << st[i].adr.house << "| Entrance: " << st[i].adr.pidy << "| Apartment: " << st[i].adr.kvart
		<< "\nPhone number: " << st[i].phoneN
		<< "\nData of birth: " << st[i].birthD.day << " " << st[i].birthD.month << " " << st[i].birthD.year
		<< "\nDate of join: " << st[i].joinD.day << " " << st[i].joinD.month << " " << st[i].joinD.year << "\n\n";
}

STUDENT inputStudent() {
	STUDENT buf;
	cout << "\nNew student: \n";
	cout << "Last name: "; cin >> buf.pi.prisv;
	cout << "First name: "; cin >> buf.pi.name;
	cout << "Country: "; cin >> buf.adr.countr;
	cout << "Region: "; cin >> buf.adr.obl;
	cout << "City: "; cin >> buf.adr.city;
	cout << "Street: "; cin >> buf.adr.strt;
	cout << "House: "; cin >> buf.adr.house;
	cout << "Entrance: "; cin >> buf.adr.pidy;
	cout << "Apartment: "; cin >> buf.adr.kvart;
	cout << "Phone number: "; cin >> buf.phoneN;
	cout << "Day of birth: "; cin >> buf.birthD.day;
	cout << "Month of birth: "; cin >> buf.birthD.month;
	cout << "Year of birth: "; cin >> buf.birthD.year;
	cout << "Day of join: "; cin >> buf.joinD.day;
	cout << "Month of join: "; cin >> buf.joinD.month;
	cout << "Year of join: "; cin >> buf.joinD.year;

	return buf;
}

STUDENT* addStudent(STUDENT* mas, int& size, STUDENT buf) {
	STUDENT* temp = new STUDENT[size + 1];
	for (int i = 0; i < size; ++i) {
		temp[i] = mas[i];
	}
	temp[size] = buf;
	delete[] mas;
	++size;
	return temp;
}

STUDENT* removeStudent(STUDENT* mas, int& size, int index) {
	if (index < 0 || index >= size) {
		cout << "Invalid index!\n";
		return mas;
	}
	if (size == 1) {
		delete[] mas;
		size = 0;
		return nullptr;
	}
	STUDENT* temp = new STUDENT[size - 1];
	int j = 0;
	for (int i = 0; i < size; ++i) {
		if (i == index) continue;
		temp[j++] = mas[i];
	}

	delete[] mas;
	--size;
	return temp;
}

STUDENT* bOnAutmn(STUDENT* mas, int size, STUDENT* newmas, int& size2) {
	delete[] newmas;
	int k = 0;
	for (int i = 0; i < size; ++i)
		if (mas[i].birthD.month == 9 || mas[i].birthD.month == 10 ||
			mas[i].birthD.month == 11) ++k;
	newmas = new STUDENT[k];
	int d = 0;
	for (int i = 0; i < size; ++i)
		if (mas[i].birthD.month == 9 || mas[i].birthD.month == 10 ||
			mas[i].birthD.month == 11) newmas[i - d] = mas[i];
		else ++d;

	size2 = k;
	return newmas;
}

STUDENT* JoinAfter25(STUDENT* mas, int size, STUDENT* newmas, int& size2) {
	delete[] newmas;
	int k = 0;
	for (int i = 0; i < size; ++i)
		if ((mas[i].joinD.month == 8 && mas[i].joinD.day > 25) || mas[i].joinD.month > 8) ++k;

	newmas = new STUDENT[k];
	int d = 0;
	for (int i = 0; i < size; ++i)
		if ((mas[i].joinD.month == 8 && mas[i].joinD.day > 25) || mas[i].joinD.month > 8) newmas[i - d] = mas[i];
		else ++d;

	size2 = k;
	return newmas;
}

void saveToFile(const char* s, STUDENT* a, int size)
{
	FILE* g;
	fopen_s(&g, "size.dat", "wb");
	fwrite(&size, sizeof(int), 1, g);
	fclose(g);
	FILE* f;
	fopen_s(&f, s, "wb");
	STUDENT dat;
	for (int i = 0; i < size; ++i)
	{
		dat = a[i];
		fwrite(&dat, sizeof(STUDENT), 1, f);
	}
	fclose(f);
}