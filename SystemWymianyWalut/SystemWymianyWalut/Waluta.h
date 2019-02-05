#pragma once

#include <iostream>
#include <fstream>
#include "pch.h"
#include <string>
#include <ctime>


using namespace std;

class Waluta
{
	string nazwa;
	double kurskupna;
	double kurssprzedazy;

public:
	Waluta();
	~Waluta();
	void pokasz();
	void zapisz(string _nazwa, double _kurskupna);
	double mnoznik();
	double zmiana();
};


