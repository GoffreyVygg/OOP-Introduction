#include "Wykladowca.h"
#include <iostream>

Wykladowca::Wykladowca(string pesel, string imie, string nazwisko, Wykladowca::StopienNaukowy stop) : Osoba(imie, nazwisko, pesel), stopien(stop)
{}

string _stopien;

void Wykladowca::wypisz() {
	cout << "   " << pesel << "\t " << wiek << "\t" << imie << " " << nazwisko << endl;
};

void Wykladowca::zapisz(fstream& plik) {
	plik << "   " << pesel << "\t " << wiek << "\t" << imie << " " << nazwisko << endl;	
}
	




