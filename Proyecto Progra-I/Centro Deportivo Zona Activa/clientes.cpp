#include "clientes.h"
#include <string>
#include <sstream>

cliente::cliente() {
	nombre = "DESCONOCIDO";
	telefono = "0000-000";
	identificacion = 0;
}	

cliente::cliente(string nombre, string telefono, int identificacion) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->identificacion = identificacion;
}

void cliente::setNombre(string nombre) {
	this->nombre = nombre;
}
void cliente::setTelefono(string telefono) {
	this->telefono = telefono;
}
void cliente::setIdentificacion(int identificacion) {
	this->identificacion = identificacion;
}
string cliente::getNombre() const {
	return nombre;
}
string cliente::getTelefono() const {
	return telefono;
}
int cliente::getIdentificacion() const {
	return identificacion;
}

string cliente::toString() {
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Telefono: " << telefono << endl;
	s << "Identificacion: " << identificacion << endl;
	return s.str();
}