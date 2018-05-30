#pragma once

const POINT operator+(const POINT& other, const POINT& other2);
const POINT operator-(const POINT& other, const POINT& other2);


const RECT operator+(const RECT& other, const POINT& other2);

const RECT operator-(const RECT& other, const POINT& other2);

const RECT operator+(const POINT& other2, const RECT& other);
const RECT operator-(const POINT& other2, const RECT& other);
const RECT operator*(const RECT& other1, const float& other2);

void operator+=(RECT& other, const POINT& other2);
void operator-=(RECT& other, const POINT& other2);

const POINT operator+(const POINT& other, const int& other2);
const POINT operator-(const POINT& other, const int& other2);
void operator+=(POINT& other, const int& other2);
void operator-=(POINT& other, const int& other2);
const RECT operator+(const RECT& other, const int& other2);
const RECT operator-(const RECT& other, const int& other2);

void operator+=(RECT& other, const int& other2);
void operator-=(RECT& other, const int& other2);


//전위
const POINT operator++(POINT& other);
//후위
const POINT operator++(POINT& other, int);

//전위
const RECT operator++(RECT& other);
//후위
const RECT operator++(RECT& other, int);
//전위
const POINT operator--(POINT& other);
//후위
const POINT operator--(POINT& other, int);
//전위
const RECT operator--(RECT& other);
//후위
const RECT operator--(RECT& other, int);

/*
ostream& operator<<(ostream& os, const POINT& other) {
	return os << "(" << other.x << "," << other.y << ")";
}

ostream& operator<<(ostream& os, const RECT& other) {
	return os << "(" << other.left << "," << other.top << "," << other.right << "," << other.bottom << ")";

}

*/
