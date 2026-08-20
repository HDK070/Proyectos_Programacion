#include "clientes.h"
#include <string>
#include <sstream>


cliente::cliente(string nombre, string telefono, int identificacion) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->identificacion = identificacion;
}
int cliente::getIdentificacion() const {
	return identificacion;
}
string cliente::getNombre() const {
	return nombre;
}
string cliente::getTelefono() const {
	return telefono;
}


