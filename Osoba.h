#include <string>
#include <fstream>
#include "Interfejs.h"
	
using namespace std;

class Osoba : public Interfejs {
private:
	void setWiek();

protected:
	string imie;
	string nazwisko;
	string pesel;
	int wiek;	

	Osoba(string imie, string nazwisko, string pesel);

public:
	void setImie (string _imie);
	string getImie();
	void setNazwisko (string _nazwisko);
	string getNazwisko();
	void setPesel (string _pesel);
	string getPesel ();
	int getWiek();
	virtual void wypisz() = 0;
	virtual void zapisz(fstream& plik) = 0;
};
