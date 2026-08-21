#include "clientes.h"
#include <string>
#include <sstream>


cliente::cliente(string nombre, string telefono, int identificacion) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->identificacion = identificacion;
}



string setNombre(string nombre) {
	this->nombre = nombre;
}
string setTelefono(string telefono) {
	this->telefono = telefono;
}
string setNombre(int identificacion){
	this->identificacion = identificacion;
}
void getNombre() const {
	return cliente::nombre;
}
void getTelefono() const {
	return cliente::telefono;
}
void getIdentificacion() const {
	return cliente::identificacion;
}


