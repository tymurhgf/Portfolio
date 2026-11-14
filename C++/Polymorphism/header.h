#pragma once
#include <iostream>
using namespace std;

//правило 5 - за зомовчуванням вже є
class Employer {
public:
    virtual void Print() = 0;
};

class President :public Employer {
public:
    void Print() override {
        cout << "Employer - President" << endl;
    }
};

class Manager :public Employer {
public:
    void Print() override {
        cout << "Employer - Manager" << endl;
    }
};

class Worker :public Employer {
public:
    void Print() override {
        cout << "Employer - Worker" << endl;
    }
};

class Figure {
public:
    virtual double area() = 0;
};

class Rectangle : public Figure {
private:
    double w;
    double h;
public:
    Rectangle() : w(0.), h(0.) {}
	Rectangle(double s) : w(s), h(s) {}
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() override {
        return w * h;
    }
};

class Circle : public Figure {
private:
    double r;
public:
    Circle() : r(0) {}
    Circle(double r) : r(r) {}
    double area() override {
        return 3.1415 * r * r;
    }
};

class RightTriangle : public Figure {
private:
    double b;
    double h;
public:
    RightTriangle() : b(0), h(0) {}
	RightTriangle(double s) : b(s), h(s) {}
    RightTriangle(double b, double h) : b(b), h(h) {}
    double area() override {
        return 0.5 * b * h;
    }
};

class Trapezia : public Figure {
private:
    double b1;
    double b2;
    double h;
public:
    Trapezia() : b1(0), b2(0), h(0) {}
	Trapezia(double s) : b1(s), b2(s), h(s) {}
	Trapezia(double b1, double b2_h) : b1(b1), b2(b2_h), h(b2_h) {}
    Trapezia(double b1, double b2, double h) : b1(b1), b2(b2), h(h) {}
    double area() override {
        return 0.5 * (b1 + b2) * h;
    }
};