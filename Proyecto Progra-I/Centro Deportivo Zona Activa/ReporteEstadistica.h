#pragma once
#include <string>
#include "GestionCanchas.h"
#include "gestionClientes.h"
#include "GestionReserva.h"
using namespace std;

class ReporteEstadisticas {
private:
	GestionCanchas* misCanchas;
	gestionClientes* misClientes;
	GestionReserva* misReservas;

	int contarReservasActivasPorCancha(Cancha* cancha);
	int contarReservasActivasPorCliente(cliente* c);
	void pausar();
	void limpiarPantalla();

public:
	ReporteEstadisticas(GestionCanchas* misCanchas, gestionClientes* misClientes,
		GestionReserva* misReservas);

	void reporteCanchaMasReservas();
	void reporteClienteMasReservas();
	void reporteIngresoTotal();
	void reportePorcentajeOcupacion();
	void reporteHorasMayorMenorReservas();

	
	void mostrarMenu();
};
