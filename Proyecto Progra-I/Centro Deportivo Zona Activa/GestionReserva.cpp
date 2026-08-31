#include "GestionReserva.h"
#include <iostream>
using namespace std;

GestionReserva::GestionReserva(GestionCanchas* misCanchas, gestionClientes* misClientes) {
	contador = 0;
	siguienteNumero = 1;
	this->misCanchas = misCanchas;
	this->misClientes = misClientes;
	for (int i = 0; i < MAX_RESERVAS; i++) {
		reservas[i] = nullptr;
	}
}

GestionReserva::~GestionReserva() {
	for (int i = 0; i < contador; i++) {
		delete reservas[i];
		reservas[i] = nullptr;
	}
}

void GestionReserva::RegistrarReserva() {
	if (contador >= MAX_RESERVAS) {
		cout << "No se pueden registrar mas reservas." << endl;
		return;
	}

	int identificacion;
	string codigoCancha;
	int franjaInicial, cantidadFranjas;

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
		return;
	}

	cout << "Ingrese el codigo de la cancha: ";
	cin >> codigoCancha;

	
	Cancha* canchaEncontrada = misCanchas->BuscarCancha(codigoCancha);
	if (canchaEncontrada == nullptr) {
		cout << "La cancha no existe." << endl;
		return;
	}

	cout << "Ingrese la franja horaria inicial (0 a 11): ";
	cin >> franjaInicial;
	cout << "Ingrese la cantidad de franjas consecutivas a reservar: ";
	cin >> cantidadFranjas;

	if (franjaInicial < 0 || cantidadFranjas <= 0 || franjaInicial + cantidadFranjas > 12) {
		cout << "Franja horaria invalida." << endl;
		return;
	}

	
	bool todasLibres = true;
	for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
		if (canchaEncontrada->getFranja(i) != 'L') {
			todasLibres = false;
			break;
		}
	}

	if (!todasLibres) {
		
		cout << "Alguna(s) franja(s) solicitada(s) no esta(n) libre(s). "
			<< "No se puede registrar la reserva; considere anotar al cliente "
			<< "en el listado de espera." << endl;
		return;
	}

	
	float monto = canchaEncontrada->getPrecio() * cantidadFranjas;
	for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
		canchaEncontrada->setFranja(i, 'O');
	}

	reservas[contador] = new Reserva(siguienteNumero, clienteEncontrado, canchaEncontrada,
		franjaInicial, cantidadFranjas, monto);
	siguienteNumero++;
	contador++;

	cout << "Reserva registrada exitosamente." << endl;
}

void GestionReserva::MostrarReservas() {
	if (contador == 0) {
		cout << "No hay reservas registradas." << endl;
		return;
	}
	for (int i = 0; i < contador; i++) {
		cout << reservas[i]->toString() << endl;
	}
}

Reserva* GestionReserva::BuscarReserva(int numero) {
	for (int i = 0; i < contador; i++) {
		if (reservas[i]->getNumero() == numero) {
			return reservas[i];
		}
	}
	return nullptr;
}

void GestionReserva::MostrarReservasPorCancha(string codigoCancha) {
	bool encontroAlguna = false;
	for (int i = 0; i < contador; i++) {
		if (reservas[i]->getCancha() != nullptr &&
			reservas[i]->getCancha()->getCodigo() == codigoCancha) {
			cout << reservas[i]->toString() << endl;
			encontroAlguna = true;
		}
	}
	if (!encontroAlguna) {
		cout << "No hay reservas para la cancha " << codigoCancha << "." << endl;
	}
}

void GestionReserva::CancelarReserva(int numero) {
	Reserva* r = BuscarReserva(numero);
	if (r == nullptr) {
		cout << "Reserva no encontrada." << endl;
		return;
	}
	if (!r->estaActiva()) {
		cout << "La reserva ya se encuentra cancelada." << endl;
		return;
	}

	r->cancelar();
	Cancha* c = r->getCancha();
	if (c != nullptr) {
		for (int i = r->getFranjaInicial(); i < r->getFranjaInicial() + r->getCantidadFranjas(); i++) {
			c->setFranja(i, 'L');
		}
	}
	cout << "Reserva cancelada. Las franjas quedaron libres." << endl;

	
}

int GestionReserva::getContador() {
	return contador;
}

Reserva* GestionReserva::obtenerReserva(int indice) {
	if (indice < 0 || indice >= contador) {
		return nullptr;
	}
	return reservas[indice];
}
