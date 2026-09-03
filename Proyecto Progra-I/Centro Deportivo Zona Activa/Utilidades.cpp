#include "Utilidades.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void limpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pausar() {
	cout << "Presione ENTER para continuar...";
	cin.ignore(100, '\n');
	cin.get();
}