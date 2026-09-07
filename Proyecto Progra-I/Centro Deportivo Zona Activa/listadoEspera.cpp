#include "listadoEspera.h"

listadoEspera::listadoEspera() {
	numConsecutivo = 0;
	canchaPtr = nullptr;
	clientePtr = nullptr;
	franja = 'H';
	estado = 'y';
	
}

listadoEspera::listadoEspera(int numConsecutivo, cliente* clientePtr, Cancha* canchaPtr, char franja, string estado) {
	this->numConsecutivo = numConsecutivo;
	this-> clientePtr = clientePtr;
	this->canchaPtr = canchaPtr;
	this->franja = franja;
	this->estado = estado;

}

void listadoEspera::setCliente(cliente* clientePtr) {
	this->clientePtr = clientePtr;
}

void listadoEspera::setCancha(Cancha* canchaPtr) {
	this->canchaPtr = canchaPtr;
}

void listadoEspera::setFranja(char franja) {
	this->franja = franja;
}

void listadoEspera::setEstado(string estado) {
	this->estado = estado;
}

int listadoEspera::getNumConsecutivo() {
	return numConsecutivo;
}

cliente* listadoEspera::getCliente() {
	return clientePtr;
}

Cancha* listadoEspera::getCancha() {
	return canchaPtr;
}

char listadoEspera::getFranja() {
	return franja;
}
string listadoEspera::getEstado() {
	return estado;
}

