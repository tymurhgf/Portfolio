#pragma once
#include <iostream>
#include <cmath>
#include "rules.h"
using namespace std;

double Perimeter(double a, double b, double c) START
	return a + b + c;
END

double Area(double a, double b, double c) START
	double p = Perimeter(a, b, c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
END

double Median(double a, double b, double c) START
	return 0.5 * sqrt(2.0 * b * b + 2.0 * c * c - a * a);
END