#include "Osoba.h"
#include <iostream>

Osoba::Osoba(string imie, string nazwisko, string pesel) : imie(imie), nazwisko(nazwisko), pesel(pesel)
{
	setWiek();
}

void Osoba::setImie(string _imie) {
	imie = _imie;
};

void Osoba::setNazwisko(string _nazwisko) {
	nazwisko = _nazwisko;
};

string Osoba::getImie() {
	return imie;
};

string Osoba::getNazwisko() {
	return nazwisko;
};

void Osoba::setPesel(string _pesel) {
	pesel = _pesel;
	setWiek();
};

string Osoba::getPesel() {
	return pesel;
};

int Osoba::getWiek() {
	return wiek;
};

void Osoba::setWiek() {
	string miesiac, _pesel;
	miesiac.insert(0, pesel);
	_pesel.insert(0, pesel);
	miesiac.erase(0, 2);
	miesiac.erase(2, 7);
	int i = atoi(miesiac.c_str());

	if (i > 20)
	{
		_pesel.erase(2, 9);
		int j = atoi(_pesel.c_str());
		wiek = 19 - j;
	}

	else if (i < 20)
	{
		_pesel.erase(2, 9);
		int j = atoi(_pesel.c_str());
		wiek = 119 - j;
	}

	else
		cout << "Nieprawid³owy pesel";
};
