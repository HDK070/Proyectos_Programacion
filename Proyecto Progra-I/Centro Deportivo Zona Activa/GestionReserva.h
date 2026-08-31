#pragma once
#include <string>
#include "Reserva.h"
#include "GestionCanchas.h"
#include "gestionClientes.h"
using namespace std;

const int MAX_RESERVAS = 120;


class GestionReserva {
private:
	Reserva* reservas[MAX_RESERVAS];
	int contador;
	int siguienteNumero;
	GestionCanchas* misCanchas;
	gestionClientes* misClientes;

public:
	GestionReserva(GestionCanchas* misCanchas, gestionClientes* misClientes);
	~GestionReserva();

	void RegistrarReserva();
	void MostrarReservas();
	Reserva* BuscarReserva(int numero);
	void MostrarReservasPorCancha(string codigoCancha);
	void CancelarReserva(int numero);
	int getContador();
	Reserva* obtenerReserva(int indice);
};
