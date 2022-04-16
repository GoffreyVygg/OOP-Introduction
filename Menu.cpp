#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(ListaObecnosci* ptr) : lista(move(ptr))
{}

void Menu::start() {

	system("clear");
	bool running = true;
	while (running)
	{
		cout << endl << "\t" << "MENU:" << endl << endl << "1. Sprawdz obecnosc" << endl <<
			"2. Lista" << endl << "3. Dodaj studenta" << endl << "4. Usun" << endl << "5. Wyczysc liste" << endl << "6. Sortuj liste" << endl <<
			"7. Zapisz liste" << endl << "8. Wczytaj liste" << endl << "9. Dodaj wykladowce" << endl << "0. Zakoncz program" << endl
			<< endl << endl;
		char wybor;
		cin >> wybor;
		string nazwa;
		switch (wybor)
		{
		case '1':
			lista->sprawdz();
			break;
		case '2':
			lista->wypisz();
			break;
		case '3':
			lista->nowyStudent();
			break;
		case '4':
			lista->usun();
			break;
		case '5':
			lista->czysc();
			break;
		case '6':
			lista->sortowanie();
			break;
		case '7':
			cout << "Podaj nazwê pliku: ";
			cin >> nazwa;
			lista->zapisz(nazwa);
			break;
		case '8':
			cout << "Podaj nazwê pliku: ";
			cin >> nazwa;
			lista->wczytaj(nazwa);
			break;
		case '9':
			lista->nowyWykladowca();
			break;
		case '0':
			running = false;
			break;
		default:
			cout << endl << "Niepoprawna komenda";
		}
		getchar();
		getchar();
		system("clear");
	}
}
