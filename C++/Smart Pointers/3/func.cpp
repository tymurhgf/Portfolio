#pragma once
#include <iostream>
#include "header.h"
using namespace std;

Fraction add(Fraction a, Fraction b) { //(a/b) + (c/d) = (a*d + c*b) / (b*d)
	int num = a.getNumerator() * b.getEnumerator() + b.getNumerator() * a.getEnumerator();
	int en = a.getEnumerator() * b.getEnumerator();
	return Fraction(num, en);
}

Fraction vidnim(Fraction a, Fraction b) { //Так як додавання тільки з -
	int num = a.getNumerator() * b.getEnumerator() - b.getNumerator() * a.getEnumerator();
	int en = a.getEnumerator() * b.getEnumerator();
	return Fraction(num, en);
}

Fraction mnoz(Fraction a, Fraction b) { //Кожне по члено перемножуємо
	int num = a.getNumerator() * b.getNumerator();
	int en = a.getEnumerator() * b.getEnumerator();
	return Fraction(num, en);
}

Fraction dil(Fraction a, Fraction b) { //Множенння але перевернуте
	if (b.getNumerator() == 0) {
		return Fraction(1, 1);
	}
	int num = a.getNumerator() * b.getEnumerator();
	int en = a.getEnumerator() * b.getNumerator();
	return Fraction(num, en);
}

void SaveToFile(Fraction& Tr)
{
	ofstream fout;
	fout.open("1.dat", ios::binary | ios::out);
	fout.write((char*)&Tr, sizeof(Tr));
	fout.close();
}

void LoadFromFile(Fraction& Tr)
{
	ifstream fin("1.dat", ios::binary);
	fin.read((char*)&Tr, sizeof(Tr));
	fin.close();
}
