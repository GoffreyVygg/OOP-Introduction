#include "Student.h"

class Wykladowca : public Osoba {
public:
	enum StopienNaukowy {
		inz, mgr, mgr_inz, dr, prof, undefined
	};
private:
	StopienNaukowy stopien;

public:
	Wykladowca(string pesel, string imie, string nazwisko, Wykladowca::StopienNaukowy);
	virtual void wypisz();
	virtual void zapisz(fstream& plik);
};
