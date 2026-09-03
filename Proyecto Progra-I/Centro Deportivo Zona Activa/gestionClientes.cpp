#include "gestionClientes.h"
#include "GestionReserva.h"
#include "clientes.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Utilidades.h"
gestionClientes::gestionClientes() {
	for (int i = 0; i < MAX; i++) {
		clientes[i] = nullptr;
		cantidadClientes = 0;
	}
}
gestionClientes::~gestionClientes() {
	for (int i = 0; i < MAX; ++i) {
		delete clientes[i];
		clientes[i] = nullptr;
	}
	cantidadClientes = 0;
}

void gestionClientes::registrarClientes() {
	if (cantidadClientes < MAX) {
		string nombre, telefono;
		int identificacion;
		cout << "Ingrese el nombre del cliente: ";
		cin >> nombre;
		cout << "Ingrese el telefono del cliente: ";
		cin >> telefono;
		cout << "Ingrese la identificacion del cliente: ";
		cin >> identificacion;
		clientes[cantidadClientes] = new cliente(nombre, telefono, identificacion);
		cantidadClientes++;
	}
	else {
		cout << "No se pueden registrar mas clientes." << endl;
	}
}

string gestionClientes::eliminarCliente(int identificacion) {
	for (int i = 0; i < cantidadClientes; i++) {
		if (clientes[i]->getIdentificacion() == identificacion) {
			clientes[i] = clientes[cantidadClientes - 1];
			clientes[cantidadClientes - 1] = nullptr;
			cantidadClientes--;
			return  "Cliente eliminado.";

		}
	}
	return "Cliente no encontrado.";
}

string gestionClientes::toString(int identificacion) {
	stringstream s;
	for (int i = 0; i < cantidadClientes; i++) {
		if (clientes[i]->getIdentificacion() == identificacion) {
			return clientes[i]->toString();
		}
	}
		return string("Cliente no encontrado");
}

string gestionClientes::listado() {
	stringstream s;
	for (int i = 0; i < cantidadClientes; i++) {
		s << "------------------------" << endl;
		s << clientes[i]->toString();
		s << "------------------------" << endl;
	}
	return s.str();
}


int gestionClientes::getCantidadClientes() {
	return cantidadClientes;
}

cliente* gestionClientes::obtenerCliente(int indice) {
	if (indice < 0 || indice >= cantidadClientes) {
		return nullptr;
	}
	return clientes[indice];
}

void gestionClientes::submenuGClientes(GestionReserva* misReservas) {
	int opcion;
	do {
		limpiarPantalla();
		cout << "\n===== GESTION DE CLIENTES =====\n";
		cout << "1. Registrar cliente\n";
		cout << "2. Eliminar cliente\n";
		cout << "3. Mostrar listado de clientes\n";
		cout << "4. Buscar cliente por identificaci"<<char(162)<<"\n";
		cout << "5. Mostrar reservas de un cliente\n";
		cout << "6. volver al menu principal\n";
		cout << "Seleccione una opci"<<char(162)<<"\n";
		cin >> opcion;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Entrada invalida." << endl;
			continue;
		}
		int identificacion;
		switch (opcion) {
		case 1:
			registrarClientes(); pausar();
			break;
		case 2:
			cout << "Ingrese la identificacion del cliente: ";
			cin >> identificacion;
			eliminarCliente(identificacion); pausar();
			break;
		case 3:
			cout << listado();
			break;
		case 4:
			cout << "Ingrese la identificacion del cliente: ";
			cin >> identificacion;
			cout << toString(identificacion);
			pausar();
			break;
		case 5:
			cout << "Ingrese la identificacion del cliente: ";
			cin >> identificacion;
			misReservas->MostrarReservasPorCliente(identificacion);
			pausar();
			break;
		case 6:
			break;
		default:
			cout << "Opci" << char(162) << "n invalida." << endl;
		}
	} while (opcion != 6);
}
