
output: main.o ListaObecnosci.o Menu.o Osoba.o Student.o Wykladowca.o
	g++ main.o ListaObecnosci.o Menu.o Osoba.o Student.o Wykladowca.o -o a.out


main.o: main.cpp
	g++ -c main.cpp
	
ListaObecnosci.o: ListaObecnosci.cpp ListaObecnosci.h
	g++ -c ListaObecnosci.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

Osoba.o: Osoba.cpp Osoba.h
	g++ -c Osoba.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

Wykladowca.o: Wykladowca.cpp Wykladowca.h
	g++ -c Wykladowca.cpp

clean: 
	rm *.o a.out