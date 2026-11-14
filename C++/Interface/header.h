#pragma once
#include <iostream>
using namespace std;

class IMethod {
public:
    virtual int Sum() = 0;
    virtual int Product() = 0;
    virtual void Show() = 0;
};

class A : public IMethod {
protected:
    int a;
public:
    A() : a(0) {}
    A(int val) : a(val) {}

    void Show() override {
        cout << "A: a= " << a << endl;
    }
};

class B : public A {
protected:
    int b;
public:
    B() : A(), b(0) {}
    B(int a, int b) : A(a), b(b) {}

    int Sum() override {
        return a + b;
    }

    int Product() override {
        return a * b;
    }

    void Show() override {
        cout << "B: a= " << a << ", b = " << b << endl;
    }
};

class C : public A {
protected:
    int c;
public:
    C() : A(), c(0) {}
    C(int a, int c) : A(a), c(c) {}

    int Sum() override {
        return a + c;
    }

    int Product() override {
        return a * c;
    }

    void Show() override {
        cout << "C: a = " << a << ", c = " << c << endl;
    }
};

class D : public B {
protected:
    int d;
public:
    D() : B(), d(0) {}
    D(int a, int b, int d) : B(a, b), d(d) {}

    int Sum() override {
        return a + b + d;
    }

    int Product() override {
        return a * b * d;
    }

    void Show() override {
        cout << "D: a = " << a << ", b = " << b << ", d = " << d << endl;
    }
};