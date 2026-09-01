#include <iostream>
#include "Menu.h"

int main() {
	GestionCanchas canchas;
	gestionClientes clientes;
	GestionReserva reservas(&canchas, &clientes);
	ReporteEstadisticas reportes(&canchas, &clientes, &reservas);

	menuPrincipal(canchas, clientes, reservas, reportes);

	return 0;
}
