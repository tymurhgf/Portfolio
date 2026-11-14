#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Fraction {
private:
	int numerator;
	int enumerator;
	friend void SaveToFile(Fraction&);
	friend void LoadFromFile(Fraction&);
public:
	Fraction() {
		numerator = rand() % 10;
		enumerator = rand() % 10 + 1;
	}
	Fraction(int num) {
		numerator = num;
		enumerator = 1;
	}
	Fraction(int num, int en) {
		numerator = num;
		if (en == 0) {
			enumerator = 1;
		}
		else {
			enumerator = en;
		}
	}
	void setNumerator(int chis) {
		numerator = chis;
	}
	void setEnumerator(int znam) {
		if (znam == 0) {
			return;
		}
		enumerator = znam;
	}
	int getNumerator() const {
		return numerator;
	}
	int getEnumerator() const {
		return enumerator;
	}
	void show() const {
		cout << numerator << "/" << enumerator << "\n";
	}

	Fraction operator+(const Fraction& other) const {
		int num = numerator * other.enumerator + other.numerator * enumerator;
		int en = enumerator * other.enumerator;
		return Fraction(num, en);
	}
	Fraction operator-(const Fraction& other) const {
		int num = numerator * other.enumerator - other.numerator * enumerator;
		int en = enumerator * other.enumerator;
		return Fraction(num, en);
	}
	Fraction operator*(const Fraction& other) const {
		int num = numerator * other.numerator;
		int en = enumerator * other.enumerator;
		return Fraction(num, en);
	}
	Fraction operator/(const Fraction& other) const {
		int num = numerator * other.enumerator;
		int en = enumerator * other.numerator;
		return Fraction(num, en);
	}

	friend ostream& operator<<(ostream& os, const Fraction& f) {
		os << f.numerator << "/" << f.enumerator;
		return os;
	}
};

Fraction add(Fraction, Fraction);
Fraction vidnim(Fraction, Fraction);
Fraction mnoz(Fraction, Fraction);
Fraction dil(Fraction, Fraction);