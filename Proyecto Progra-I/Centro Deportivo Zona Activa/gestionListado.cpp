#include "gestionListado.h"
#include "listadoEspera.h"
#include "Cancha.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

gestionListado::gestionListado() {
	for (int i = 0; i < MAX; i++) {
		num[i] = nullptr;
	}
	cantidad = 0;
}
gestionListado::~gestionListado() {
	for (int i = 0; i < cantidad; ++i) {
		delete num[i];
		num[i] = nullptr;
	}
	cantidad = 0;
}
bool gestionListado::existeDuplicado(cliente* clientePtr, Cancha* canchaPtr,int posicionfranja) {
	for (int i = 0; i < cantidad; i++) {
		if( num[i] != nullptr &&
			num[i]->getCliente() == clientePtr &&num[i]->getCancha() == canchaPtr ) {
			return false;
		}
	}
	return true;
}
void gestionListado::registrarCliente(cliente* clientePtr, Cancha* canchaPtr,int posicionfranja) {
	if (clientePtr == nullptr || canchaPtr == nullptr) {
		cout << "Error: Cliente o Cancha invalido." << endl;
		return;
	}

	if (cantidad >= MAX) {
		cout << "No se pueden registrar mas clientes." << endl;
		return;
	}

	if (canchaPtr->getFranja(posicionfranja) == 'm' || canchaPtr->getFranja(posicionfranja) == 'M') {
		cout << "No se puede regsitrar un cliente en el listado en una cancha en mantenimiento" << endl;
		return;
	}

	int nextConsecutivo = 1;
	for (int i = 0; i < cantidad; i++) {
		if (num[i] != nullptr) {
			if (num[i]->getNumConsecutivo() >= nextConsecutivo) {
				nextConsecutivo = num[i]->getNumConsecutivo() + 1;
			}
		}
	}

	

	// Si se detecta duplicado para la misma cancha, no registrar
	if (existeDuplicado(clientePtr, canchaPtr, posicionfranja)) {
		cout << "El cliente ya se encuentra en el listado de espera para esa cancha." << endl;
		return;
	}

	num[cantidad] = new listadoEspera(nextConsecutivo, clientePtr, canchaPtr, posicionfranja, "esperando");
	cantidad++;

	cout << "Cliente registrado en listado de espera con numero " << nextConsecutivo << "." << endl;
}

void gestionListado::cambiarEstado() {

}


