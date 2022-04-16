#include <fstream>
using namespace std;

class Interfejs {
public:
	virtual void wypisz() = 0;
	virtual void zapisz(fstream& plik) = 0;
};
