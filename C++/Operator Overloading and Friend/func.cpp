#pragma once
#include <iostream>
#include <cmath>
#include "header.h"
using namespace std;

void Vector2d::setX(double x) { this->x = x; }
void Vector2d::setY(double y) { this->y = y; }
double Vector2d::getX() const { return x; }
double Vector2d::getY() const { return y; }

double distance(const Vector2d& v1, const Vector2d& v2) {
	double vx = v1.x - v2.x;
	double vy = v1.y - v2.y;
	return sqrt(vx * vx + vy * vy);
}
void reset(Vector2d& v) {
	v.x = 0.;
	v.y = 0.;
}
ostream& operator <<(ostream& os, const Vector2d& v) {
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}
Vector2d operator +(double num, const Vector2d& v) {
	double nX = v.x + num;
	double nY = v.y + num;
	Vector2d res(nX, nY);
	return res;
}

Vector2d Vector2d::operator +(double num) {
	Vector2d temp;
	temp.x = x + num;
	temp.y = y + num;
	return temp;
}
Vector2d Vector2d::operator +(const Vector2d& other) {
	Vector2d temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	return temp;
}

Vector2d Vector2d::operator -() 
{
	Vector2d temp;
	temp.x = -x;
	temp.y = -y;
	return temp;
}
Vector2d Vector2d::operator -(double num)
{
	Vector2d temp;
	temp.x = x - num;
	temp.y = y - num;
	return temp;
}
Vector2d Vector2d::operator -(const Vector2d& other)
{
	Vector2d temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	return temp;
}

Vector2d Vector2d:: operator *(double num)
{
	Vector2d temp;
	temp.x = x * num;
	temp.y = y * num;
	return temp;
}
Vector2d Vector2d::operator *(const Vector2d& other)
//Векторний добуток двох 3D-векторів але Z ігноруємо(z=1) - матричне представлення.
//x = y1 * z2 - z1 * y2 = y1 * 1 - 1 * y2 = y1 - y2
//y = z1 * x2 - x1 * z2 = 1 * x2 - x1 * 1 = x2 - x1
{
	Vector2d temp;
	temp.x = y - other.y;
	temp.y = other.x - x;
	return temp;
}

Vector2d Vector2d::operator /(double num) {
	Vector2d temp;
	if (num != 0) {
		temp.x = x / num;
		temp.y = y / num;
	}
	else {
		cout << "Error: Division by zero." << endl;
		temp.x = x;
		temp.y = y;
	}
	return temp;
}

void Vector2d::operator +=(double num)
{
	x += num;
	y += num;
}
void Vector2d::operator +=(const Vector2d& other)
{
	x += other.x;
	y += other.y;
}

void Vector2d::operator -=(double num)
{
	x -= num;
	y -= num;
}
void Vector2d::operator -=(const Vector2d& other)
{
	x -= other.x;
	y -= other.y;
}

void Vector2d::operator *=(double num)
{
	x *= num;
	y *= num;
}
void Vector2d::operator *=(const Vector2d& other)
{
	double tempX = y - other.y;
	double tempY = other.x - x;
	x = tempX;
	y = tempY;
}

void Vector2d::operator /=(double num) {
	if (num != 0) {
		x /= num;
		y /= num;
	}
	else {
		cout << "Error: Division by zero." << endl;
	}
}