#include "Osoba.h"

class Student : public Osoba {

private:
	int numerAlbumu;
	bool obecnosc;

public:
	Student(int numerAlbumu, bool obecnosc, string pesel, string imie, string nazwisko);

	void obecny();
	void nieobecny();
	int getNumer();
	bool getObecnosc();
	void setNumer(int _numer);
	virtual void wypisz();
	virtual void zapisz(fstream& plik);
};
