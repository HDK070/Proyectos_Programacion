#include <iostream>
#include <string>
#include "gestionClientes.h"
#include "GestionReserva.h"
#include "GestionCanchas.h"
using namespace std;
void Menu()  {
	int opcion;
	do {
		cout << "\tCENTRO DEPORTIVO ZONA ACTIVA" << endl;
		cout << "1. Gestion de Canchas" << endl;
		cout << "2. Gestion de Clientes" << endl;
		cout << "3. Gestion de Reservas" << endl;
		cout << "4. Gestion de listado de espera" << endl;
		cout << "5. Reportes y estadisticas" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese su opcion: ";
		cin >> opcion;
		if (cin.fail()) { //Detecta si la entrada es invalida (no es un numero)
			cin.clear(); // reinicia el estado de error de cin
			cin.ignore(100, '\n'); // saca del buffer la entrada invalida
			cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
		}else if (opcion < 1 || opcion > 6) {
		cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
		}else {
		switch (opcion) {
		case 1:
			cout << "Opcion 1 seleccionada" << endl;
			break;
		case 2:
			cout << "Opcion 2 seleccionada" << endl;
			break;
		case 3:
			cout << "Opcion 3 seleccionada" << endl;
			break;
		case 4:
			cout << "Opcion 4 seleccionada" << endl;
			break;
		case 5:
			cout << "opcion 5 seleccionada" << endl;
			break;
		case 6:
			cout << "saliendo del programa..." << endl;
			break;
			}
		}
	} while (opcion != 6);
}
int main() {
	Menu();
	return 0;
}