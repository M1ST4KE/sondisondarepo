#pragma once
#include <iostream>
#include <string>

class Userprywatny
{
private:
	std::string PESEL;	//11 cyfr
	std::string haslo;
	std::string imie;
	std::string nazwisko;
public:
	Userprywatny();
	~Userprywatny();
};

