#include <iostream>
#include <vector>
#include "header.h"
using namespace std;

void main() {
    int ch = -1;
    int constnt = 0;
    int rem = 0;
    vector<int> v1, v2, v3, v4, v5, v6, v7;

    while (ch != 0) {
        cout << "1.Find min\n";
        cout << "2.Find max\n";
        cout << "3.Sort zrost\n";
        cout << "4.Sort spad\n";
        cout << "5.Add constant\n";
        cout << "6.Subtract constant\n";
        cout << "7.Remove specified value\n";
        cout << "0.Exit\n";
        cout << "Your choice: ";
        cin >> ch;

        if (ch == 1) {
            v1 = { 14, -3, 27, 0, 8, -3, 19 };
            FindMin(v1);
        }
        else if (ch == 2) {
            v2 = { 42, 11, -9, 73, 5, 73, 18 };
            FindMax(v2);
        }
        else if (ch == 3) {
            v3 = { 50, 12, 99, -4, 23, 7, 41 };
            SortZrostVect(v3);
        }
        else if (ch == 4) {
            v4 = { 15, -20, 84, 3, 62, 0, 29 };
            SortSpadVect(v4);
        }
        else if (ch == 5) {
            v5 = { 10, 20, 30, 40, 50 };
            cout << "Enter constant to add: ";
            cin >> constnt;
            AddConstant(v5, constnt);
        }
        else if (ch == 6) {
            v6 = { 100, 75, 50, 25, 10 };
            cout << "Enter constant to subtract: ";
            cin >> constnt;
            SubConstant(v6, constnt);
        }
        else if (ch == 7) {
            v7 = { 4, 8, 15, 8, 16, 23, 8, 42 };
            cout << "Enter value to remove: ";
            cin >> rem;
            RemoveVal(v7, rem);
        }
        else if (ch == 0) {
        }
        else {
            cout << "Error.\n";
        }
        cout << "\n";
    }

	cin.get();
	cin.get();
}
