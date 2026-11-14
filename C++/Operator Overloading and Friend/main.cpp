#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
	Vector2d v1(3., 4.);
	Vector2d v2(1., 2.);
	cout << "v1 = " << v1 << endl;
	cout << "v2 = " << v2 << endl;
	cout << endl;

	Vector2d v3 = v1 + 2.;
	cout << "v1 + 2 = \t" << v3 << endl;
	Vector2d v4 = v1 + v2;
	cout << "v1 + v2 = \t" << v4 << endl;

	Vector2d v5 = v1 - 1.;
	cout << "v1 - 1 = \t" << v5 << endl;
	Vector2d v6 = v1 - v2;
	cout << "v1 - v2 = \t" << v6 << endl;
	Vector2d v7 = -v1;
	cout << "-v1 = \t" << v7 << endl;
	Vector2d v8 = v1 * 2.;
	cout << "v1 * 2 = \t" << v8 << endl;
	Vector2d v9 = v1 * v2;
	cout << "v1 * v2 = \t" << v9 << endl;
	Vector2d v10 = v1 / 2.;
	cout << "v1 / 2 = \t" << v10 << endl;

	Vector2d v11 = v1;
	v11 += 3.;
	cout << "v1 += 3 = \t" << v11 << endl;
	Vector2d v12 = v1;
	v12 += v2;
	cout << "v1 += v2 = \t" << v12 << endl;

	Vector2d v13 = v1;
	v13 -= 1.;
	cout << "v1 -= 1 = \t" << v13 << endl;
	Vector2d v14 = v1;
	v14 -= v2;
	cout << "v1 -= v2 = \t" << v14 << endl;

	Vector2d v15 = v1;
	v15 *= 2.;
	cout << "v1 *= 2 = \t" << v15 << endl;
	Vector2d v16 = v1;
	v16 *= v2;
	cout << "v1 *= v2 = \t" << v16 << endl;

	Vector2d v17 = v1;
	v17 /= 2.;
	cout << "v1 /= 2 = \t" << v17 << endl;

	cout << "\nDistance: " << distance(v1, v2) << endl;
	Vector2d vTST = v1;
	reset(vTST);
	cout << "After reset: " << vTST << endl;

	Vector2d v18 = 10.0 + v1;
	cout << "10.0 + v1 = " << v18 << endl;

	cin.get();
	cin.get();
}