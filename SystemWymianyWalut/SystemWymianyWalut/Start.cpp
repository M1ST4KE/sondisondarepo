#include "pch.h"
#include "Start.h"
#include <fstream>

using namespace std;

Start::Start()
{
}


Start::~Start()
{
}

void Start::wyswietl()
{
	cout << "-------------" << endl;
	cout << "MENU STARTOWE" << endl;
	cout << "-------------" << endl << endl;

	cout << "1. Zaloguj" << endl;
	cout << "2. Zarejestruj " << endl;
	cout << "3. Wyjscie" << endl;
}


void Start::opcja()
{
	cin >> wybor;
	switch (wybor)
	{
	case '1':
		system("cls");
		zaloguj();
		break;

	case '2':
		system("cls");
		zarejestruj();
		break;	

	case '3':
		exit(0);
		break;

	default: cout << "Nie ma takiej opcji!";
		getchar();
		getchar();
	}
}

void Start::run()
{
	for (;; )
	{
		system("cls");
		wyswietl();
		opcja();
	}
}

void Start::zaloguj()
{
	string login;
	string logintxt;

	cout << "Podaj login: ";
	cin >> login;

	logintxt = login + ".txt";

	if (plikistnieje(logintxt))
	{
		fstream logowanie; 

		logowanie.open(logintxt);
		string typ;
		string haslo;
		string podanehaslo;

			getline(logowanie, typ);
			getline(logowanie, login);
			getline(logowanie, haslo);

			do {
				cout << "Podaj haslo: ";
				cin >> podanehaslo;
				
				if (podanehaslo != haslo)
				{
					system("cls");
					cout << "Bledne haslo" << endl;
				}
			} while (podanehaslo != haslo);

			cout << "zalogowano" << endl;


			if (typ == "1")
			{
				string imie, nazwisko;
				getline(logowanie, imie);
				getline(logowanie, nazwisko);
				Prywatny p1(login, haslo, imie, nazwisko, 1);
				logowanie.close();
				p1.run();
			}
			else if (typ == "2")
			{
				string nazwafirmy;
				getline(logowanie, nazwafirmy);
				Firmowy f1(login, haslo, nazwafirmy, 1);
				logowanie.close();
				f1.run();
			}
			else if (typ == "3") 
			{
				string nazwauzytkownika;
				getline(logowanie, nazwauzytkownika);
				Grupowy g1(login, haslo, nazwauzytkownika, 0.9);
				logowanie.close();
				g1.run();
			}

		getchar();
		getchar();
	}
	else {
		cout << "Nie ma takiego konta" << endl;
		getchar();
		getchar();
	}
}

void Start::zarejestruj() 
{
		cout << "Wybierz typ konta" << endl;
		cout << "1 - prywatne" << endl;
		cout << "2 - firmowe " << endl;
		cout << "3 - grupowe" << endl;

		cin >> typ;
		switch (typ)
		{
		case '1':
			system("cls");
			rejestracjaprywatna();
			break;

		case '2':
			system("cls");
			rejestracjafirmowa();
			break;

		case '3':
			system("cls");
			rejestracjagrupowa();
			break;
		default:
			cout << "Wybierz poprawna opcje!\n";
			getchar();
			zarejestruj();
		}
}

void Start::rejestracjaprywatna()
{
	string pesel;
	string peseltxt;
	string historia;

	cout << "Podaj PESEL: ";
	cin >> pesel;

	regex wzor("[0-9]{11}");
	if (regex_match(pesel, wzor))
	{
		peseltxt = pesel + ".txt";
		historia = "h-" + peseltxt;
		if (plikistnieje(peseltxt))
		{
			cout << "Login zajety" << endl;
			getchar();
			getchar();
		}
		else {
			zapisprywatny(pesel, peseltxt, historia);
			getchar();
			getchar();
		}
	}
	else
	{
		cout << "Niepoprawne\n";
		getchar();
		getchar();
	}

}

void Start::zapisprywatny(string pesel, string nazwadane, string nazwahistoria)
{
	fstream plik1, plik2;
	string haslo, imie, nazwisko;
	plik1.open(nazwadane, ios::out | ios::app);
	plik1 << typ << endl;
	plik1 << pesel << endl;
	cout << "Podaj haslo: ";
	cin >> haslo;
	plik1 << haslo << endl;
	cout << "Podaj imie: ";
	cin >> imie;
	plik1 << imie << endl;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	plik1 << nazwisko << endl;
	plik1.close();

	plik2.open(nazwahistoria, ios::out | ios::app);
	plik2.close();
}

void Start::rejestracjafirmowa()
{
	string regon;
	string regontxt;
	string historia;

	cout << "Podaj REGON: ";
	cin >> regon;

	regex wzor("[0-9]{9}");
	if (regex_match(regon, wzor))
	{
		regontxt = regon + ".txt";
		historia = "h-" + regontxt;
		if (plikistnieje(regontxt))
		{
			cout << "Login zajety" << endl;
			getchar();
			getchar();
		}
		else {
			zapisfirmowy(regon, regontxt, historia);
			getchar();
			getchar();
		}
			}
	else
	{
		cout << "Niepoprawne\n";
		getchar();
		getchar();
	}
}

void Start::zapisfirmowy(string regon, string nazwadane, string nazwahistoria)
{
	fstream plik1, plik2;
	string haslo, nazwafirmy;
	plik1.open(nazwadane, ios::out | ios::app);
	plik1 << typ << endl;
	plik1 << regon << endl;
	cout << "Podaj haslo: ";
	cin >> haslo;
	plik1 << haslo << endl;
	cout << "Podaj nazwe firmy: ";
	cin >> nazwafirmy;
	plik1 << nazwafirmy << endl;
	plik1.close();

	plik2.open(nazwahistoria, ios::out | ios::app);
	plik2.close();
}

void Start::rejestracjagrupowa()
{
	string id;
	string idtxt;
	string historia;

	cout << "Podaj 8 cyfrowy login: ";
	cin >> id;

	regex wzor("[0-9]{8}");
	if (regex_match(id, wzor))
	{
		idtxt = id + ".txt";
		historia = "h-" + idtxt;
		if (plikistnieje(idtxt))
		{
			cout << "Login zajety" << endl;
			getchar();
			getchar();
		}
		else {
			zapisgrupowy(id, idtxt, historia);
			getchar();
			getchar();
		}
	}
	else
	{
		cout << "Niepoprawne\n";
		getchar();
		getchar();
	}
}

void Start::zapisgrupowy(string id, string nazwadane, string nazwahistoria)
{
	fstream plik1, plik2;
	string haslo, nazwauzytykownika;
	plik1.open(nazwadane, ios::out | ios::app);
	plik1 << typ << endl;
	plik1 << id << endl;
	cout << "Podaj haslo: ";
	cin >> haslo;
	plik1 << haslo << endl;
	cout << "Podaj nazwe uzytkownika: ";
	cin >> nazwauzytykownika;
	plik1 << nazwauzytykownika << endl;
	plik1.close();

	plik2.open(nazwahistoria, ios::out | ios::app);
	plik2.close();
}

bool Start::plikistnieje(string nazwapliku) 
{
	fstream plik;
	
	plik.open(nazwapliku, ios::in);  
	if (plik.is_open())
	{
		plik.close();
		return true;
	}
	plik.close();
	return false;
} 

