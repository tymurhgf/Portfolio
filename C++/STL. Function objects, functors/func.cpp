#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "header.h"
using namespace std;

void print(const vector<int>& vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}

void FindMin(const vector<int>& vec) {
    MinFind findMin;
    cout << "Vector: ";
    print(vec);
    auto it = min_element(vec.begin(), vec.end(), findMin);

    cout << "Minimum value: ";
    if (it != vec.end()) {
        cout << *it << "\n";
    }
    else {
        cout << "vector is empty\n";
    }
}

void FindMax(const vector<int>& vec) {
    MaxFind findMax;
    cout << "Vector: ";
    print(vec);
    auto it = max_element(vec.begin(), vec.end(), findMax);

    cout << "Maximum value: ";
    if (it != vec.end()) {
        cout << *it << "\n";
    }
    else {
        cout << "vector is empty\n";
    }
}

void SortZrostVect(vector<int> vec) {
    SortZrost zr;
    cout << "Vector: ";
    print(vec);

    sort(vec.begin(), vec.end(), zr);

    cout << "Sorted po zrost: ";
    print(vec);
}

void SortSpadVect(vector<int> vec) {
    SortSpad sp;
    cout << "Vector: ";
    print(vec);
    sort(vec.begin(), vec.end(), sp);

    cout << "Sorted po spad: ";
    print(vec);
}

void AddConstant(vector<int> vec, int constant) {
    AddConst add(constant);
    cout << "Vector: ";
    print(vec);

    transform(vec.begin(), vec.end(), vec.begin(), add);

    cout << "After adding " << constant << ": ";
    print(vec);
}

void SubConstant(vector<int> vec, int constant) {
    SubConst subtr(constant);
    cout << "Vector: ";
    print(vec);

    transform(vec.begin(), vec.end(), vec.begin(), subtr);

    cout << "After subtracting " << constant << ": ";
    print(vec);
}

void RemoveVal(vector<int> vec, int valueToRemove) {
    IsTargetValue pred(valueToRemove);
    cout << "Vector: ";
    print(vec);

    auto newEnd = remove_if(vec.begin(), vec.end(), pred);
    vec.erase(newEnd, vec.end());

    cout << "After removing value " << valueToRemove << ": ";
    print(vec);
}