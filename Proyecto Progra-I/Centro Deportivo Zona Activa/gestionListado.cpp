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
	for (int i = 0; i < MAX; ++i) {
		delete num[i];
		num[i] = nullptr;
	}
	cantidad = 0;
}
bool gestionListado::existeDuplicado(cliente* clientePtr, Cancha* canchaPtr,int posicionfranja) {
	for (int i = 0; i < cantidad; i++) {
		if( num[i]-> == clientePtr &&
			num[i]-> == canchaPtr &&
			num[i]-> == posicionfranja) {
			return false;
		}
	}
	return true;
}
void gestionListado::registrarCliente(cliente* clientePtr, Cancha* canchaPtr) {
	if (clientePtr == nullptr) {
		cout << "Error: puntero a cliente nulo." << endl;
		return;
	}

	if (cantidad >= MAX) {
		cout << "No se pueden registrar mas clientes." << endl;
		return;
	}

	// Si se detecta duplicado para la misma cancha, no registrar
	if (existeDuplicado(clientePtr, canchaPtr)) {
		cout << "El cliente ya se encuentra en el listado de espera para esa cancha." << endl;
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
	
	// Obtener franja específica de la cancha si se proporciona
	char franja = '0'; // valor por defecto = no asignado
	if (canchaPtr != nullptr) {
		int posicion = -1;
		cout << "Ingrese la posicion de la franja (0-11) para la cancha: ";
		if (!(cin >> posicion)) {
			// entrada no valida, limpiar buffer y mantener valor por defecto
			cin.clear();
			string _tmp;
			getline(cin, _tmp);
			cout << "Entrada invalida. Se usara franja por defecto." << endl;
		} else if (posicion < 0 || posicion > 11) {
			cout << "Posicion invalida. Se usara franja por defecto." << endl;
		} else {
			franja = canchaPtr->getFranja(posicion);
		}
	}

	num[cantidad] = new listadoEspera(nextConsecutivo, clientePtr, canchaPtr, franja, "esperando");
	cantidad++;

	cout << "Cliente registrado en listado de espera con numero " << nextConsecutivo << "." << endl;
}


