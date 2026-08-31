#include "gestionClientes.h"
#include "GestionReserva.h"
#include "clientes.h"
#include <iostream>
#include <sstream>
#include <string>

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
		return string("Cliente no encontrado");
	}
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


