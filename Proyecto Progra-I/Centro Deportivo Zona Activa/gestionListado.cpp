#include "gestionListado.h"
#include "listadoEspera.h"
#include "Cancha.h"
#include "Utilidades.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

gestionListado::gestionListado() {
	for (int i = 0; i < Maximo; i++) {
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

	bool gestionListado::existeDuplicado(cliente * clientePtr, Cancha * canchaPtr, int posicionfranja) {

		for (int i = 0; i < cantidad; i++) {
			if (num[i] != nullptr &&
				num[i]->getCliente() == clientePtr && 
				num[i]->getCancha() == canchaPtr &&
				num[i]->getPosicionFranja() == posicionfranja) {
				return true;
			}
		}
	return false;
	}

	void gestionListado::registrarCliente(cliente* clientePtr, Cancha* canchaPtr, int posicionfranja) {
		if (clientePtr == nullptr || canchaPtr == nullptr) {
			cout << "Error: Cliente o Cancha invalido." << endl;
			return;
		}

		if (cantidad >= Maximo) {
			cout << "No se pueden registrar mas clientes." << endl;
			return;
		}

		if (posicionfranja < 0 || posicionfranja > 11) {
			cout << "Posicion de franja invalida." << endl;
		}

		char estadoFranja = canchaPtr->getFranja(posicionfranja);
		if (estadoFranja != 'O') {
			cout << "Solo se puede anotar en espera si la franja esta ocupada." << endl;
			return;
		}

		if (existeDuplicado(clientePtr, canchaPtr, posicionfranja)) {
			cout << "El cliente ya se encuentra en el listado de espera para esa cancha y franja." << endl;
			return;
		}

		if (canchaPtr->getFranja(posicionfranja) == 'm' || canchaPtr->getFranja(posicionfranja) == 'M') {
		cout << "No se puede regsitrar un cliente en el listado en una cancha en mantenimiento" << endl;
		return;
		}

	int nextConsecutivo = 1;
	for (int i = 0; i < cantidad; i++) {
		if (num[i] != nullptr && 
			num[i]->getNumConsecutivo() >= nextConsecutivo) {
				nextConsecutivo = num[i]->getNumConsecutivo() + 1;
		}
	}


	if (existeDuplicado(clientePtr, canchaPtr, posicionfranja)) {
		cout << "El cliente ya se encuentra en el listado de espera para esa cancha." << endl;
		return;
	}

	num[cantidad] = new listadoEspera(nextConsecutivo, clientePtr, canchaPtr, estadoFranja, "esperando", posicionfranja);
	cantidad++;

	cout << "Cliente registrado en listado de espera con numero " << nextConsecutivo << "." << endl;
}

bool gestionListado::hayEsperandoPara(Cancha* canchaPtr, int posicionFranja) {
	for (int i = 0; i < cantidad;i++) {
		if (num[i] != nullptr && num[i]->getCancha() == canchaPtr &&
			num[i]->getPosicionFranja() == posicionFranja &&
			num[i]->getEstado() == "esperando") {
			return true;
		}
	}
	return false;
}

string gestionListado::listado() {
	stringstream s;
	if (cantidad == 0) {
		s << "No hay clientes en el listado de espera." << endl;
		return s.str();
	}
	for (int i = 0; i < cantidad;i++) {
		s << "-------------------------" << endl;
		s << "Numero: " << num[i]->getNumConsecutivo() << endl;
		s << "Cliente: " << (num[i]->getCliente() ? num[i]->getCliente()->getNombre() : "N/A") << endl;
		s << "Cancha: " << (num[i]->getCancha() ? num[i]->getCancha()->getCodigo() : "N/A") << endl;
		s << "Franja: " << num[i]->getPosicionFranja() << endl;
		s << "Estado: " << num[i]->getEstado() << endl;
		s << "-------------------------" << endl;
	}
	return s.str();
}

string gestionListado::toString(int numConsecutivo) {
	for (int i = 0; i < cantidad; i++) {
		if (num[i] != nullptr && num[i]->getNumConsecutivo() == numConsecutivo) {
			stringstream s;
			s << "Numero: " << num[i]->getNumConsecutivo() << endl;
			s << "Cliente: " << (num[i]->getCliente() ? num[i]->getCliente()->getNombre() : "N/A") << endl;
			s << "Cancha: " << (num[i]->getCancha() ? num[i]->getCancha()->getCodigo() : "N/A") << endl;
			s << "Franja: " << num[i]->getPosicionFranja() << endl;
			s << "Estado: " << num[i]->getEstado() << endl;
			return s.str();
		}
	}
	return string("Registro no encontrado.");
}

void gestionListado::cambiarEstado(int numConsecutivo, string nuevoEstado) {
	for (int i = 0;i < cantidad;i++) {
		if (num[i] != nullptr &&
			num[i]->getNumConsecutivo() == numConsecutivo) {
			num[i]->setEstado(nuevoEstado);
			cout << "Estado actualizado exitosamente." << endl;
			return;
		}
	}
	cout << "Registro no enctrado." << endl;
}

void gestionListado::submenuGL(GestionCanchas* misCanchas, gestionClientes* misClientes) {
	int opcion;
	do {
		limpiarPantalla();
		cout << "\n===== GESTION DE LISTADO DE ESPERA =====\n";
		cout << "1. Registrar cliente en listado de espera\n";
		cout << "2. Mostrar listado de espera\n";
		cout << "3. Buscar registro por numero\n";
		cout << "4. Cambiar estado de un registro\n";
		cout << "5. Volver al menu principal\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Entrada invalida." << endl;
			continue;
		}
		switch (opcion) {
		case 1: {
			int identificacion;
			string codigoCancha;
			int posicion;

			cout << "Ingrese la identificacion del cliente: ";
			cin >> identificacion;

			cliente* clienteEncontrado = nullptr;
			for (int i = 0; i < misClientes->getCantidadClientes(); i++) {
				cliente* c = misClientes->obtenerCliente(i);
				if (c != nullptr && c->getIdentificacion() == identificacion) {
					clienteEncontrado = c;
					break;
				}
			}
			if (clienteEncontrado == nullptr) {
				cout << "El cliente no se encuentra registrado." << endl;
				pausar();
				break;
			}

			cout << "Ingrese el codigo de la cancha: ";
			cin >> codigoCancha;
			Cancha* canchaEncontrada = misCanchas->BuscarCancha(codigoCancha);
			if (canchaEncontrada == nullptr) {
				cout << "La cancha no existe." << endl;
				pausar();
				break;
			}

			cout << "Ingrese la posicion de la franja (0-11): ";
			cin >> posicion;

			registrarCliente(clienteEncontrado, canchaEncontrada, posicion);
			pausar();
			break;
		}
		case 2:
			cout << listado();
			pausar();
			break;
		case 3: {
			int numero;
			cout << "Ingrese el numero de registro: ";
			cin >> numero;
			cout << toString(numero);
			pausar();
			break;
		}
		case 4: {
			int numero;
			string nuevoEstado;
			cout << "Ingrese el numero de registro: ";
			cin >> numero;
			cout << "Ingrese el nuevo estado (esperando/asignado/cancelado): ";
			cin >> nuevoEstado;
			cambiarEstado(numero, nuevoEstado);
			pausar();
			break;
		}
		case 5:
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (opcion != 5);
}




