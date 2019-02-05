#pragma once

#include <iostream>
#include <fstream>
#include "pch.h"
#include <string>
#include "Waluta.h"
#include "Start.h"

using namespace std;

class Konto
{
public:
	string login;
	string haslo;
	double mnoznik;
	Konto();
	~Konto();
	void menu();
	void run();
	Waluta wczytajkursy(int n);
	};

class Prywatny: public Konto
{
private:
	string imie;
	string nazwisko;
public:
	Prywatny(string _login, string _haslo, string _imie, string _nazwisko, double _mnoznik);
	~Prywatny();

};

class Firmowy : public Konto
{
private:
	string nazwafirmy;
public:
	Firmowy(string _login, string _haslo, string _nazwafirmy, double _mnoznik);
	~Firmowy();

};

class Grupowy : public Konto
{
private:
	string nazwauzytkownika;
public:
	Grupowy(string _login, string _haslo, string _nazwauzytkownika, double _mnoznik);
	~Grupowy();

};