#pragma once
#include <string>
#include "Cancha.h"
#include "clientes.h"
using namespace std;
class Reserva {
private:
	int numero;
	cliente* clienteAsociado;
	Cancha* canchaAsociada;
	int franjaInicial;
	int cantidadFranjas;
	float monto;
	bool activa; 

public:
	Reserva();
	Reserva(int numero, cliente* clienteAsociado, Cancha* canchaAsociada,
		int franjaInicial, int cantidadFranjas, float monto);

	int getNumero();
	cliente* getCliente();
	Cancha* getCancha();
	int getFranjaInicial();
	int getCantidadFranjas();
	float getMonto();
	bool estaActiva();
	string getEstadoTexto(); 

	bool incluyeFranja(int posicion); 

	void cancelar();
	string toString();
};
