#pragma once

#include <iostream>
#include <fstream>
#include "pch.h"
#include <string>
#include <regex>
#include "Konto.h"

using namespace std;

class Start
{
private:
	char wybor;
	char typ;
public:
	Start();
	~Start();
	void run();
	void wyswietl();
	void opcja();
	void zarejestruj();
	void zaloguj();
	void rejestracjaprywatna();
	void rejestracjafirmowa();
	void rejestracjagrupowa();
	void zapisprywatny(string pesel, string nazwadane, string nazwahistoria);
	void zapisfirmowy(string regon, string nazwadane, string nazwahistoria);
	void zapisgrupowy(string login, string nazwadane, string nazwahistoria);
	bool plikistnieje(string nazwapliku);
	
};

