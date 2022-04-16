#include "Wykladowca.h"
#include <vector>

class ListaObecnosci {
	vector<Osoba*> lista;
	void dodajStudenta(int numerAlbumu, bool obecnosc, string pesel, string imie, string nazwisko);
	void dodajWykladowce(string pesel, string imie, string nazwisko, Wykladowca::StopienNaukowy);
public:
	void wypisz();
	void wypiszOsobe(Interfejs* doWypisania);
	void usun();
	void czysc();
	void zapisz(string nazwa);
	void wczytaj(string nazwa);
	void sprawdz();
	void sortowanie();
	void nowyStudent();
	void nowyWykladowca();
};
