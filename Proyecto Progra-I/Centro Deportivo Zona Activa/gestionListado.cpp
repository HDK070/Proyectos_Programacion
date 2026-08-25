#include "gestionListado.h"
#include <iostream>
#include <sstream>
#include <string>



gestionListado::gestionListado() {
	cantidad = 0;
}

/*void gestionListado::registrarCliente(cliente* clientePtr) {
	new listadoEspera num[cantidad+1]->setCliente(cliente* clientePtr);
	cantidad++;
}*/
string listado();
string toString(int numConsecutivo);
bool existeDuplicado(cliente* clientePtr, Cancha* canchaPtr);

