#include "pch.h"
#include "Konto.h"

Konto::Konto()
{
}

Konto::~Konto()
{
}

Prywatny::Prywatny(string _login, string _haslo, string _imie, string _nazwisko, double _mnoznik)
{
	login = _login;
	haslo = _haslo;
	imie = _imie;
	nazwisko = _nazwisko;
	mnoznik = _mnoznik;
}

Prywatny::~Prywatny()
{
}

Firmowy::Firmowy(string _login, string _haslo, string _nazwafirmy, double _mnoznik)
{
	login = _login;
	haslo = _haslo;
	nazwafirmy = _nazwafirmy;
	mnoznik = _mnoznik;
}

Firmowy::~Firmowy()
{
}

Grupowy::Grupowy(string _login, string _haslo, string _nazwauzytkownika, double _mnoznik)
{
	login = _login;
	haslo = _haslo;
	nazwauzytkownika = _nazwauzytkownika;
	mnoznik = _mnoznik;
}

Grupowy::~Grupowy()
{
}


void Konto::run()
{
	system("cls");

	Waluta tablica = wczytajkursy(ilewalut());
	tablica.pokasz();
	getchar();
	getchar();

	for (;; )
	{
		system("cls");
		menu();	
	}
}

Waluta Konto::wczytajkursy(int n)
{
	fstream plik;
	plik.open("kursy.txt");
	Waluta* tablica = new Waluta[n];
	double liczba;
	string wyraz;

	for (int i = 0; i < n; i++)
	{
		plik >> wyraz;
		plik >> liczba;
		tablica[i].zapisz(wyraz, liczba);
	}
	
	
	plik.close();
	return *tablica;
}




void Konto::menu()
{

		cout << "------------" << endl;
		cout << "    MENU    " << endl;
		cout << "------------" << endl << endl;

		cout << "1. Zobacz kursy" << endl;
		cout << "2. Kup walute " << endl;
		cout << "3. Sprzedaj walute" << endl;
		cout << "4. Dane konta" << endl;
		cout << "5. Historia transakcji " << endl;
		cout << "6. Wyjscie" << endl;


		char x;
			cin >> x;
			switch (x)
			{
			case '1':
				system("cls");

				cout<<"XD";
				break;

			case '2':
				system("cls");
				break;

			case '3':
				exit(0);
				break;

			default: cout << "Nie ma takiej opcji!";
				getchar();
				getchar();
			}
	
}


int Konto::ilewalut()
{
	string linia;
	int licznik = 0;
	fstream plik;
	plik.open("kursy.txt");
	while (getline(plik, linia)) licznik++;
	plik.close();
	return licznik;
}