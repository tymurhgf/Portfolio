#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
    Employer* emp = new President();
    emp->Print();
    delete emp;

    emp = new Manager();
    emp->Print();
    delete emp;

    emp = new Worker();
    emp->Print();
    delete emp;

    cout << "\n";

    Figure* fig = new Rectangle(4.3, 5.2);
    cout << "S rectangle: " << fig->area() << endl;
    delete fig;

    fig = new Circle(3.7);
    cout << "S circle: " << fig->area() << endl;
    delete fig;

    fig = new RightTriangle(3.2, 4.9);
    cout << "S right triangle: " << fig->area() << endl;
    delete fig;

    fig = new Trapezia(3.1, 5.8, 4.4);
    cout << "S trapezia: " << fig->area() << endl;
    delete fig;
	
	cin.get();
	cin.get();
}