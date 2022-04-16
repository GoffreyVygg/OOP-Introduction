#include "ListaObecnosci.h"

using namespace std;

class Menu {

private:
	ListaObecnosci* lista;

public:
	Menu(ListaObecnosci* nowaLista);
	void start();
};
