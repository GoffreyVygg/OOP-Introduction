#include "ListaObecnosci.h"
#include <iostream>

using namespace std;

void ListaObecnosci::dodajStudenta(int numerAlbumu, bool obecnosc, string pesel, string imie, string nazwisko)
{
	lista.push_back(new Student(numerAlbumu, obecnosc, pesel, imie, nazwisko));
};

void ListaObecnosci::wypisz() 
{
	if (lista.empty() == true)
	std::cout << "Lista jest pusta";

	else 
	{
		cout << endl<< "LP" << "  " << "Nr albumu" << "\t" 
		<< "Ob" << "  " << "Pesel" << "\t " << "Wiek" << "\t" << "Imię i Nazwisko" <<  endl;
		int np = 0;
		for (auto i = lista.begin(); i != lista.end(); i++)
		{
			Student* stud = dynamic_cast <Student*> (*i);
			if (stud != nullptr)
			{		
				cout << ++np;
				wypiszOsobe(*i);
			}
		}
		cout << endl<< "LP" << "  " << "Pesel" << "\t " << "Wiek" << "\t" << "Imię i Nazwisko" <<  endl;
		for (auto i = lista.begin(); i != lista.end(); i++)
		{
			Wykladowca* wyk = dynamic_cast <Wykladowca*> (*i);
			if (wyk != nullptr)
			{
				cout << ++np;
				wypiszOsobe(*i);
			}
		}
	}
};

void ListaObecnosci::usun()
{
	if (lista.empty() == true)
	cout << "Lista jest pusta";

	else 
	{
		int np = 0;
		wypisz();
		cout << endl << "Wybierz numer porzadkowy studenta który ma zostać usunięty: ";
		cin >> np;
		
		if (np < 0 || np > lista.size() +1) 
		cout << "Nie zdecydowałeś się nikogo usunąć";
		
		else
		{
			lista.erase(lista.begin() + np -1);
			cout << "Student usunięty pomyślnie";
		}
	}
};
	
void ListaObecnosci::czysc() 
{
	if (lista.empty() == true)
	cout << "Lista jest pusta";

	else
	{	
		int szesc;
		cout << "Aby usunąć zawartość listy, wciśnij klawisz ";
		cout << "\"6\" i zatwierdź wybór enterem: ";
		cin >> szesc;
		if (szesc == 6)
		{
			lista.clear();
			cout << "Lista została wyczyszczona";
		}

		else
		cout << "Lista nie została wyczyszczona";	
	}
};

void ListaObecnosci::zapisz(string nazwa) {
	if (lista.empty() == true)
	cout << "Lista jest pusta";

	else 
	{
		fstream plik;
		plik.open(nazwa, ios::out);
		plik << "STUDENCI:" << endl << "LP" << "  " << "Nr albumu" << "\t" << "Ob" << "  " << "Pesel" << "\t " << "Wiek" << "\t" << "Imię i Nazwisko" <<  endl;
		int np = 0;		
		for (auto i = lista.begin(); i != lista.end(); i++)
		{
			Student* stud = dynamic_cast <Student*> (*i);
			if (stud != nullptr)
			{
				plik << np +1;
				(*i)->zapisz(plik);
				np++;		
			}
		}
		plik << endl<< "WYKŁADOWCY:" << endl << "LP" << "  " << "Pesel" << "\t " << "Wiek" << "\t" << "Imię i Nazwisko" <<  endl;
		for (auto i = lista.begin(); i != lista.end(); i++)
		{
			Wykladowca* wyk = dynamic_cast <Wykladowca*> (*i);
			if (wyk != nullptr)
			{
				plik << np +1;
				(*i)->zapisz(plik);
				np++;	
			}
		}
		cout << "Lista została zapisana";
		plik.close();
	}
};
	
void ListaObecnosci::wczytaj(string nazwa) {
	cout<<"Uwaga, jeśli w programie istnieje jakaś lista, spowoduje to jej usunięcie" 		<< endl <<"Wybierz \"8\", aby kontynuować: ";
	int w;
	cin >> w;
	if (w==8)
	{
		fstream plik;
		plik.open(nazwa, ios::in);	
		if (plik.good()==false)
		cout << "Plik nie istnieje";

		else
		{
			lista.clear();
			string imie, nazwisko, pesel;
			bool obecnosc;
			int numer, wiek, lp;	
			string smietnik;
			getline (plik, smietnik);
			getline (plik, smietnik);
			do
			{
				plik >> lp;
				plik >> numer;
				plik >> obecnosc;
				plik >> pesel;
				plik >> wiek;
				plik >> imie;
				plik >> nazwisko;	
				dodajStudenta (numer, obecnosc, pesel, imie, nazwisko);
			}
			while(!plik.eof());		
		}
		lista.pop_back();
		plik.close();
		cout << "Lista wczytana pomyślnie";
	}

	else
	cout << "Anulowano odczyt z pliku";
};

void ListaObecnosci::sprawdz () {
	if (lista.empty() == true)
	cout << "Lista jest pusta";
	else 
	{
		int np = 0;
		for (auto i = lista.begin(); i != lista.end(); i++)
		{
			Student* stud = dynamic_cast<Student*>((*i));
			if (stud != nullptr) {
				cout << np++;
				stud->wypisz();
				cout << "Wybierz 1 jeśli student jest obecny, 2 jeśli nie: ";
				int o;
				cin >> o;

				if (o == 1)
					stud->obecny();

				else if (o == 2)
					stud->nieobecny();
			}
		}
		cout << "Osiągnięto koniec listy";
	}
};

void ListaObecnosci::sortowanie() {
	if (lista.empty() == true)
	cout << "Lista jest pusta";

	else 
	{
//		cout << "Wybierz 1 aby sortować według numeru indeksu, 2 aby sortować alfabetycznie: ";
//		int tryb;
//		cin >> tryb;

//		if (tryb==1)
//		{
//			cout << "Wybierz 1 aby sortować rosnąco, 2 aby malejąco: ";
//			int sort;
//			cin >> sort;
//			if (sort==1)
//			{
//				for (auto i = lista.begin(); i != lista.end(); i++)
//				{
//					for (auto j = lista.begin() + 1; j != lista.end(); j++)
//					{
//						if ((*(j-1)).getNumer() > (*j).getNumer())
//						{
//							auto dom = *(j - 1);
//							*(j-1) = *(j);
//							*j = dom;			
//						}
//					}
//				}
//			}
//
//			else if (sort==2)
//			{
//				for (auto i = lista.begin(); i != lista.end(); i++)
//				{
//					for (auto j = lista.begin() + 1; j != lista.end(); j++)
//					{
//						if ((*(j-1)).getNumer() < (*j).getNumer())
//						{
//							auto dom = *(j - 1);
//							*(j-1) = *(j);
//							*j = dom;			
//						}
//					}
//				}
//			}
//
//			else
//			cout << "Niewłaściwa komenda" << endl;
//		}
//
//		else if (tryb==2)
//		{
			cout << "Wybierz 1 aby sortować rosnąco, 2 aby malejąco: ";
			int sort;
			cin >> sort;
			if (sort==1)
			{
				for (auto i = lista.begin(); i != lista.end(); i++)
				{
					for (auto j = lista.begin() + 1; j != lista.end(); j++)
					{
						if ((*(j-1))->getNazwisko() > (*j)->getNazwisko())
						{
							auto dom = *(j - 1);
							*(j-1) = *(j);
							*j = dom;			
						}
					}
				}
			}

			else if (sort==2)
			{
				for (auto i = lista.begin(); i != lista.end(); i++)
				{
					for (auto j = lista.begin() + 1; j != lista.end(); j++)
					{
						if ((*(j-1))->getNazwisko() < (*j)->getNazwisko()){
							auto dom = *(j - 1);
							*(j-1) = *(j);
							*j = dom;			
						}
					}
				}
			}

			else
			cout << "Niewłaściwa komenda";	
		}
	
		std::cout << "Sortowanie zakończone";
};

void ListaObecnosci::nowyStudent () {
	int na;
	string pes, imi, nazw;
	cout << "Podaj numer albumu: ";
	cin >> na;
	cout << "Podaj pesel: ";
	cin >> pes;	
	cout << "Podaj imię: ";
	cin >> imi;
	cout << "Podaj nazwisko: ";
	cin >> nazw;
	dodajStudenta (na, false, pes, imi, nazw);
	cout << "Student dodany pomyślnie";
};

void ListaObecnosci::nowyWykladowca() {
	string pesel, imie, nazwisko,stopienString;
	Wykladowca::StopienNaukowy stopien;
	cout << "Podaj pesel: ";
	cin >> pesel;
	cout << "Podaj imię: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj stopien naukowy:  ";
	cin >> stopienString;
	dodajWykladowce(pesel, imie, nazwisko, [stopienString]() {
		if (stopienString == "dr")return Wykladowca::StopienNaukowy::dr;
		if (stopienString == "prof")return Wykladowca::StopienNaukowy::prof;
		if (stopienString == "inz")return Wykladowca::StopienNaukowy::inz;
		if (stopienString == "mgr")return Wykladowca::StopienNaukowy::mgr;
		return Wykladowca::StopienNaukowy::undefined;
		}());
	cout << "Wykladowca dodany pomyslnie" << endl;
}

void ListaObecnosci::dodajWykladowce(string pesel, string imie, string nazwisko, Wykladowca::StopienNaukowy stopien) {
	Wykladowca w(pesel, imie, nazwisko, stopien);
	lista.push_back(new Wykladowca(pesel, imie, nazwisko, stopien));
}

void ListaObecnosci::wypiszOsobe(Interfejs* doWypisania) {
	doWypisania->wypisz();
}
