#pragma once
#include <iostream>
using namespace std;

class Vector2d {
private:
	double x, y;
public:
	Vector2d() : x(0.), y(0.) {}
	Vector2d(double val) : x(val), y(val) {}
	Vector2d(double x, double y) { this->x = x; this->y = y; }

	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;

	friend double distance(const Vector2d& v1, const Vector2d& v2);
	friend void reset(Vector2d& vec);

	friend ostream& operator <<(ostream& os, const Vector2d& v);
	friend Vector2d operator +(double num, const Vector2d& v);

	Vector2d operator +(double num);
	Vector2d operator +(const Vector2d& other);

	Vector2d operator -();
	Vector2d operator -(double num) ;
	Vector2d operator -(const Vector2d& other);

	Vector2d operator *(double num) ;
	Vector2d operator *(const Vector2d& other);

	Vector2d operator /(double num);

	void operator +=(double num);
	void operator +=(const Vector2d& other);

	void operator -=(double num);
	void operator -=(const Vector2d& other);

	void operator *=(double num);
	void operator *=(const Vector2d& other);

	void operator /=(double num);

};
