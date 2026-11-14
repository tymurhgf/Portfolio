#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
    IMethod* p = new B(5, 10);
    p->Show();
    cout << "Sum: " << p->Sum() << endl;
    cout << "Product: " << p->Product() << "\n\n";
    delete p;

    p = new C(4, 7);
    p->Show();
    cout << "Sum: " << p->Sum() << endl;
    cout << "Product: " << p->Product() << "\n\n";
    delete p;

    p = new D(2, 3, 4);
    p->Show();
    cout << "Sum: " << p->Sum() << endl;
    cout << "Product: " << p->Product() << endl;
    delete p;

	cin.get();
	cin.get();
}