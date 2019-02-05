// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;

class  Radio
{
public:
	bool stan;
	int kanał;
};



class Silnik
{
private:
	Silnik operator=(Silnik wrum);
public:
	bool stan;
	int szybkosc;
	int identyfikator;
};

class Samolot
{
public:
	int paliwo;
	int dystans;
	int x;
	int y;
	int z;
	int wysokosc;	
	char* Sygnatura;
	const int masa;
	Silnik psilnik;
	Radio &objekt;

	Samolot();
	~Samolot();
	Samolot(int fuel, int distance, int a, int b, int c, int high);
	Samolot(const Samolot &model, int korekta);
	friend void pokaz(Samolot &model);
	Samolot operator=(Samolot model);
};

Silnik Silnik::operator=(Silnik wrum)
{
	this->stan = wrum.stan;
	this->szybkosc = wrum.szybkosc;
	this->identyfikator = wrum.identyfikator;
	return wrum;
}








Samolot::Samolot(const Samolot &model, int korekta)
{
	cout << "KOPIUJACY\n";
	paliwo = model.paliwo;
	dystans = model.dystans;
	x = model.x;
	y = model.y;
	z = model.z;
	wysokosc = (model.wysokosc-korekta);

}

Samolot::Samolot(int fuel, int distance, int a, int b, int c, int high)
{
	
	cout << "WIEL\n";
	paliwo = fuel;
	dystans = distance;
	x = a;
	y = b;
	z = c;
	wysokosc = high;

}

Samolot::Samolot()
{
	cout << "BEZ\n";
}

Samolot::~Samolot()
{
	cout << "DEZ\n";
}

void pokaz(Samolot &model)
{
		cout << " \n";
		cout << "Paliwo: " << model.paliwo << endl;
		cout << "Dystans: " << model.dystans << endl;
		cout << "X: " << model.x << endl;
		cout << "Y: " << model.y << endl;
		cout << "Z: " << model.z << endl;
		cout << "Wysokosc: " << model.wysokosc <<endl;
}

Samolot Samolot::operator=(Samolot model)
{
	this->paliwo = model.paliwo;
	this->dystans = model.dystans;
	this->x = model.x;
	this->y = model.y;
	this->z = model.z;
	this->wysokosc = model.wysokosc;
	return model;
}

int main()
{
	Samolot Concorde(10, 10, 10, 10, 10, 10);
	Samolot Boeing;
	pokaz(Concorde);
	pokaz(Boeing);
	Samolot Airbus(Concorde, 2);
	pokaz(Airbus);
	Boeing = Concorde;
	pokaz(Boeing);
}

