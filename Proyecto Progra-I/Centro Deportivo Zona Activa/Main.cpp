#include <iostream>
#include "Menu.h"

int main() {
	GestionCanchas canchas;
	gestionClientes clientes;
	gestionListado listado;
	GestionReserva reservas(&canchas, &clientes, &listado);
	ReporteEstadisticas reportes(&canchas, &clientes, &reservas);
	menuPrincipal(canchas, clientes, reservas, listado, reportes);

	return 0;
}
