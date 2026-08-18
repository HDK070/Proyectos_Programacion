#include "clientes.h"
#include <string>
using namespace std;

cliente::cliente() {
	this->nombre = "Desconocido";
	this->telefono = "Desconocido";
	this->identificacion = 0;
}
cliente::cliente(string nombre, string telefono, int identificacion) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->identificacion = identificacion;
}
cliente cliente::buscarClienteXID(int identificacion) {
	// Implementation for searching client by ID
}
void cliente::mostrarReservaCliente(int identificacion) {
	// Implementation for displaying client's reservations
}

void menuCliente() {
	int opcion;
	do {
		cout << "\tMENU CLIENTE" << endl;
		cout << "1. Registrar Cliente" << endl;
		cout << "2. Buscar Cliente por ID" << endl;
		cout << "3. Mostrar Reservas del Cliente" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese su opcion: ";
		cin >> opcion;
		if (cin.fail()) { //Detecta si la entrada es invalida (no es un numero)
			cin.clear(); // reinicia el estado de error de std::cin
			cin.ignore(100, '\n'); // saca del buffer la entrada invalida
			cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
		}
		else if (opcion < 1 || opcion > 4) {
			cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
		}
		else {
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
				cout << "Saliendo del menu de clientes..." << endl;
				break;
			}
		}
	} while (opcion != 4);
}

string cliente::toString() const {
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Telefono: " << telefono << endl;
	s << "Identificacion: " << identificacion << endl;
	return s.str();
}
cliente::~cliente() {
	cout << "Se ha eliminado al cliente: " << nombre << endl;
}


