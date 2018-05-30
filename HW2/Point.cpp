#pragma once
#include "header.h"
#include "Point.h"

Point::Point() :x(0.0), y(0.0) {};

Point::Point(float a, float b) :x(a), y(b) {}
Point::Point(double a, double b) : x(a), y(b)
{
}
;
Point::Point(int a, int b) :x((float)a), y((float)b) {};


Point::Point(const Point & q) :x(q.x), y(q.y) {}
Point::Point(const POINT &q) : x(q.x), y(q.y)
{
}
;

Point Point::operator+(const Point&a) {

	return Point(x + a.x, y + a.y);
}

Point Point::operator+(const POINT &a)
{
	return Point(x + a.x, y + a.y);
}

Point Point::operator+(const int &a)
{

	return Point(x + a, y + a);
	// TODO: 여기에 반환 구문을 삽입합니다.
}
Point Point::operator+(const float &a)
{
	return Point(x + a, y+ a);
}
Point Point::operator-(const float &a)
{
	return Point(x - a, y - a);
}
Point Point::operator-(const Point&a) {
	return Point(x - a.x, y - a.y);
}


/*
*/
void Point::SetPoint(const float a, const float b) {
	x = a;
	y = b;
}

Point& Point::operator=(const Point& p)
{
	x = p.x;
	y = p.y;
	return *this;
	// TODO: 여기에 반환 구문을 삽입합니다.
}
Point& Point::operator=(const Point&& p)
{

	x = p.x;
	y = p.y;
	return *this;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

