#include "pch.h"
#include "Waluta.h"

Waluta::Waluta()
{
	
}


Waluta::~Waluta()
{
}

void Waluta::pokasz()
{
	cout << nazwa << endl;
	cout << kurskupna << endl;
	cout << kurssprzedazy << endl;
}

void Waluta::zapisz(string _nazwa, double _kurskupna)
{
	nazwa = _nazwa;
	kurskupna = _kurskupna*mnoznik();
	kurssprzedazy = kurskupna+zmiana();
}


double Waluta::mnoznik()
{
	srand(time(NULL));

	double wylosowana_liczba1 = (rand() % 9) + 0;
	double wylosowana_liczba2 = (rand() % 2) + 1;
	double liczba = wylosowana_liczba1 / 100;
	if (wylosowana_liczba2 == 2)
		liczba = 1 - liczba;
	else
		liczba = 1 + liczba;
	return liczba;
}

double Waluta::zmiana()
{
	srand(time(NULL));

	double wylosowana_liczba1 = (rand() % 9) + 0;
	double liczba = wylosowana_liczba1 / 100;
	return liczba;
}