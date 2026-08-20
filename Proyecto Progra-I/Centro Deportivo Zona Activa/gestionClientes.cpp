#include "gestionClientes.h"
#include "GestionReserva.h"
#include <iostream>
#include <sstream>
#include <string>

// mostrar las reservas realizadas por un cliente especifico. aca va la funcion


gestionClientes::gestionClientes(){
	cliente* clientes[MAX];
	this->tam = MAX;
	this->cantidadClientes = 0;
}

string gestionClientes::listado() {
	stringstream s;
	for (int i = 0; i < cantidadClientes; i++) {
		s << "------------------------" << endl;
		s << "Nombre: " << clientes[i]->getNombre() << endl;
		s << "Telefono: " << clientes[i]->getTelefono() << endl;
		s << "Identificacion: " << clientes[i]->getIdentificacion() << endl;
		s << "------------------------" << endl;
	}
	return s.str();
}

void gestionClientes::registrarClientes() {
	if (cantidadClientes < tam) {
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
			delete clientes[i];
			cantidadClientes--;
			return  "Cliente eliminado.";
			
		}
	}
	return "Cliente no encontrado.";
}

string gestionClientes::toString(int identificacion) {
	stringstream s;
	for (int i = 0; i < cantidadClientes; i++) {
		if (clientes[i] && clientes[i]->getIdentificacion() == identificacion) {
			s << "Nombre: " << clientes[i]->getNombre() << endl;
			s << "Telefono: " << clientes[i]->getTelefono() << endl;
			s << "Identificacion: " << clientes[i]->getIdentificacion() << endl;
			return s.str();			
		}
	}
	return string("Cliente no encontrado");
}




