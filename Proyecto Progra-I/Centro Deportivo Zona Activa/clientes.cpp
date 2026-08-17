#include "clientes.h"
#include <string>

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
string cliente::toString() {
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Telefono: " << telefono << endl;
	s << "Identificacion: " << identificacion << endl;
	return s.str();
}
cliente::~cliente() {
	cout << "Se ha eliminado al cliente: " << nombre << endl;
}


