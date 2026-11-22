#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class MinFind {
public:
    bool operator()(int a, int b) const {
        return a < b;
    }
};

class MaxFind {
public:
    bool operator()(int a, int b) const {
        return a < b;
    }
};

class SortZrost {
public:
    bool operator()(int a, int b) const {
        return a < b;
    }
};

class SortSpad {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

class AddConst {
private:
    int konst;
public:
    AddConst(int val) : konst(val) {}
    int operator()(int x) const {
        return x + konst;
    }
};

class SubConst {
private:
    int konst;
public:
    SubConst(int val) : konst(val) {}
    int operator()(int x) const {
        return x - konst;
    }
};

class IsTargetValue {
private:
    int target;
public:
    IsTargetValue(int value) : target(value) {}
    bool operator()(int x) const {
        return x == target;
    }
};

void print(const vector<int>& vec);
void FindMin(const vector<int>& vec);
void FindMax(const vector<int>& vec);
void SortZrostVect(vector<int> vec);
void SortSpadVect(vector<int> vec);
void AddConstant(vector<int> vec, int constant);
void SubConstant(vector<int> vec, int constant);
void RemoveVal(vector<int> vec, int valueToRemove);
