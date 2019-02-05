// operatory.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;

typedef float real;

class LiczbaZespolona
{
private:
	float RE;
	float IM;
public:
	LiczbaZespolona() :RE(0), IM(0) {}
	LiczbaZespolona(real a, real b);
	LiczbaZespolona operator+=(LiczbaZespolona l1);
	LiczbaZespolona operator+(LiczbaZespolona l1);
	LiczbaZespolona operator-(LiczbaZespolona l1);
	friend LiczbaZespolona operator+(const LiczbaZespolona& l1, const LiczbaZespolona& l2);
	friend LiczbaZespolona operator-(const LiczbaZespolona& l1, const LiczbaZespolona& l2);
	real operator[](int v);
	bool operator!=(LiczbaZespolona& l1);
	bool operator==(LiczbaZespolona& l1);	LiczbaZespolona operator=(LiczbaZespolona l1);	friend istream& operator>>(istream& s, LiczbaZespolona& l2);	friend ostream& operator<<(ostream& s, const LiczbaZespolona& l1);
	LiczbaZespolona operator++(int);
	LiczbaZespolona operator+=(real x);
	LiczbaZespolona operator()(real a, real b);
};

LiczbaZespolona::LiczbaZespolona(float a, float b) 
{
	RE = a;
	IM = b;
}
LiczbaZespolona operator+(const LiczbaZespolona& l1, const LiczbaZespolona& l2)
{
	return LiczbaZespolona(l1.RE + l2.RE, l1.IM + l2.IM);
}
LiczbaZespolona operator-(const LiczbaZespolona& l1, const LiczbaZespolona& l2)

{
	return LiczbaZespolona(l1.RE - l2.RE, l1.IM - l2.IM);
}
LiczbaZespolona LiczbaZespolona::operator+=( LiczbaZespolona l1)
{
	this->RE += l1.RE;
	this->IM += l1.IM;

	return LiczbaZespolona();
}
LiczbaZespolona LiczbaZespolona::operator+(LiczbaZespolona l1)
{
	this->RE = this->RE + l1.RE;
	this->IM = this->RE + l1.IM;
	return LiczbaZespolona();
}
LiczbaZespolona LiczbaZespolona::operator-(LiczbaZespolona l1)
{
	this->RE = this->RE - l1.RE;
	this->IM = this->RE - l1.IM;
	return LiczbaZespolona();
}
real LiczbaZespolona::operator[](int v)
{
	if (v == 0)
		return this->RE;
	else if (v == 1)
		return this->IM;
	return 0;
}
bool LiczbaZespolona::operator!=(LiczbaZespolona& l1)
{
	if ((this->RE != l1.RE) && (this->IM != l1.IM))
		return true;
	else
		return false;
}
bool LiczbaZespolona::operator==(LiczbaZespolona& l1)
{
	if ((this->RE == l1.RE) && (this->IM == l1.IM))
		return true;
	else
		return false;
}istream& operator>>(istream & s, LiczbaZespolona & l1)
{
	s >> l1.RE >> l1.IM;
	return s;
}ostream& operator<<(ostream& s, const LiczbaZespolona & l1)
{
	s << "(" << l1.RE << "," << l1.IM << ")" << endl;
	return s;
}
LiczbaZespolona LiczbaZespolona::operator=(LiczbaZespolona l1)
{
	this->RE = l1.RE;
	this->RE = l1.IM;
	return l1;
}
LiczbaZespolona LiczbaZespolona::operator++(int)
{
	(this->RE)++;
	return LiczbaZespolona();
}LiczbaZespolona LiczbaZespolona::operator()(real a, real b)
{
	this->RE = a;
	this->RE = b;
	return LiczbaZespolona();
}
LiczbaZespolona LiczbaZespolona::operator+=(real x)
{
	this->RE += x;
	return LiczbaZespolona();
}




int main()
{

	LiczbaZespolona z1(3, 10);
	LiczbaZespolona z2(4, 5);

	z1++;
	z1++;
	z1++;
	cout << z1;

	return 0;


}

