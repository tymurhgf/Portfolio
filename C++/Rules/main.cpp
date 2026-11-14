#pragma once
#include <iostream>
#include <cmath>
#include "rules.h"
using namespace std;

void main() START
    double a, b, c;

    PRINT "Enter sides of the triangle: ";
    INPUT a >> b >> c;

    CHECK (a + b > c AND a + c > b AND b + c > a) START

		double perimeter = Perimeter(a, b, c);
		double area = Area(a, b, c);
		double median_a = Median(a, b, c);

    PRINT "Perimeter: " << perimeter << "\n";
    PRINT "Area: " << area << "\n";
    PRINT "Median to side a: " << median_a << "\n"; END

    OTHER START
		PRINT "Triangle does not exist.\n"; END

        STOP
        STOP
END