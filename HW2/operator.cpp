#include "header.h"
#include "operator.h"
const POINT operator+(const POINT& other, const POINT& other2)
{
	return POINT{ other.x + other2.x, other.y + other2.y };
}
const POINT operator-(const POINT& other, const POINT& other2)
{
	return POINT{ other.x - other2.x, other.y - other2.y };
}


const RECT operator+(const RECT& other, const POINT& other2)
{
	return RECT{ other.left + other2.x, other.top + other2.y,other.right + other2.x, other.bottom + other2.y };
}

const RECT operator-(const RECT& other, const POINT& other2)
{
	return RECT{ other.left - other2.x, other.top - other2.y,other.right - other2.x, other.bottom - other2.y };
}

const RECT operator+(const POINT& other2, const RECT& other)
{
	return RECT{ other.left + other2.x, other.top + other2.y,other.right + other2.x, other.bottom + other2.y };
}
const RECT operator-(const POINT& other2, const RECT& other)
{
	return RECT{ other.left - other2.x, other.top - other2.y,other.right - other2.x, other.bottom - other2.y };
}
const RECT operator*(const RECT & other1, const float & other2)
{
	return RECT{ LONG(other1.left*other2) ,  LONG(other1.top*other2)
		, LONG(other1.right*other2) ,  LONG(other1.bottom*other2) };
}

void operator+=(RECT& other, const POINT& other2)
{
	other.left += other2.x;
	other.top += other2.y;
	other.right += other2.x;
	other.bottom += other2.y;
}
void operator-=(RECT& other, const POINT& other2)
{
	other.left -= other2.x;
	other.top -= other2.y;
	other.right -= other2.x;
	other.bottom -= other2.y;
}


const POINT operator+(const POINT& other, const int& other2) {
	return POINT{ other.x + other2,other.y + other2 };
}
const POINT operator-(const POINT& other, const int& other2) {
	return POINT{ other.x - other2,other.y - other2 };
}

void operator+=(POINT& other, const int& other2) {
	other.x += other2;
	other.y += other2;
}
void operator-=(POINT& other, const int& other2) {
	other.x -= other2;
	other.y -= other2;
}

const RECT operator+(const RECT& other, const int& other2) {
	return RECT{ other.left + other2,
		other.top + other2,
		other.right + other2,
		other.bottom + other2 };
}
const RECT operator-(const RECT& other, const int& other2) {
	return RECT{ other.left - other2,
		other.top - other2,
		other.right - other2,
		other.bottom - other2 };
}

void operator+=(RECT& other, const int& other2) {

	other.left += other2;
	other.top += other2;
	other.right += other2;
	other.bottom += other2;
}
void operator-=(RECT& other, const int& other2) {

	other.left -= other2;
	other.top -= other2;
	other.right -= other2;
	other.bottom -= other2;

}


//전위
const POINT operator++(POINT& other) {
	return POINT{ other.x += 1,other.y += 1 };

}
//후위
const POINT operator++(POINT& other, int) {

	POINT output = other;

	other.x++;
	other.y++;

	return output;
}


//전위
const RECT operator++(RECT& other) {
	other.left += 1, other.right += 1, other.top += 1, other.bottom += 1;
	return other;

}
//후위
const RECT operator++(RECT& other, int) {

	RECT output = other;

	other.left += 1, other.right += 1, other.top += 1, other.bottom += 1;

	return output;
}

//전위
const POINT operator--(POINT& other) {
	return POINT{ other.x -= 1,other.y -= 1 };

}
//후위
const POINT operator--(POINT& other, int) {

	POINT output = other;

	other.x--;
	other.y--;

	return output;
}


//전위
const RECT operator--(RECT& other) {
	other.left -= 1, other.right -= 1, other.top -= 1, other.bottom -= 1;
	return other;

}
//후위
const RECT operator--(RECT& other, int) {

	RECT output = other;

	other.left -= 1, other.right -= 1, other.top -= 1, other.bottom -= 1;

	return output;
}

/*
ostream& operator<<(ostream& os, const POINT& other) {
return os << "(" << other.x << "," << other.y << ")";
}

ostream& operator<<(ostream& os, const RECT& other) {
return os << "(" << other.left << "," << other.top << "," << other.right << "," << other.bottom << ")";

}

*/
