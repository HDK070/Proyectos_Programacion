#include "Reserva.h"
#include <sstream>
#include <iomanip>
using namespace std;

Reserva::Reserva() {
	numero = 0;
	clienteAsociado = nullptr;
	canchaAsociada = nullptr;
	franjaInicial = -1;
	cantidadFranjas = 0;
	monto = 0.0f;
	activa = false;
}

Reserva::Reserva(int numero, cliente* clienteAsociado, Cancha* canchaAsociada,
	int franjaInicial, int cantidadFranjas, float monto) {
	this->numero = numero;
	this->clienteAsociado = clienteAsociado;
	this->canchaAsociada = canchaAsociada;
	this->franjaInicial = franjaInicial;
	this->cantidadFranjas = cantidadFranjas;
	this->monto = monto;
	this->activa = true;
}

int Reserva::getNumero() { return numero; }
cliente* Reserva::getCliente() { return clienteAsociado; }
Cancha* Reserva::getCancha() { return canchaAsociada; }
int Reserva::getFranjaInicial() { return franjaInicial; }
int Reserva::getCantidadFranjas() { return cantidadFranjas; }
float Reserva::getMonto() { return monto; }
bool Reserva::estaActiva() { return activa; }

string Reserva::getEstadoTexto() {
	return activa ? "Activa" : "Cancelada";
}

bool Reserva::incluyeFranja(int posicion) {
	return posicion >= franjaInicial && posicion < franjaInicial + cantidadFranjas;
}

void Reserva::cancelar() {
	activa = false;
}

string Reserva::toString() {
	stringstream s;
	s << "Reserva #" << numero
		<< " | Cliente: " << (clienteAsociado ? clienteAsociado->getNombre() : "N/A")
		<< " | Cancha: " << (canchaAsociada ? canchaAsociada->getCodigo() : "N/A")
		<< " | Franja inicial: " << franjaInicial
		<< " | Cantidad de franjas: " << cantidadFranjas
		<< " | Monto: " << fixed << setprecision(2) << monto
		<< " | Estado: " << getEstadoTexto();
	return s.str();
}
