#include "Student.h"
#include <iostream>

Student::Student(int numerAlbumu, bool obecnosc, string pesel, string imie, string nazwisko) : numerAlbumu(numerAlbumu),
obecnosc(obecnosc), Osoba(imie, nazwisko, pesel)
{}

void Student::wypisz() {
	cout << "   " << numerAlbumu << "\t" << obecnosc << "   " << pesel << "\t " << wiek << "\t" << imie << " " << nazwisko << endl;
};

void Student::zapisz(fstream& plik) {
	plik << "   " << numerAlbumu << "\t" << obecnosc << "   " << pesel << "\t " << wiek << "\t" << imie << " " << nazwisko << endl;
};

void Student::obecny() {
	obecnosc = true;
};

void Student::nieobecny() {
	obecnosc = false;
};

int Student::getNumer() {
	return numerAlbumu;
};

bool Student::getObecnosc() {
	return obecnosc;
};

void Student::setNumer(int _numer) {
	numerAlbumu = _numer;
};