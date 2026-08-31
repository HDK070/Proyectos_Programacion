#include <iostream>
#include "GestionCanchas.h"
#include "gestionClientes.h"
#include "GestionReserva.h"
#include "ReporteEstadistica.h"
using namespace std;


void menuPrincipal(GestionCanchas& canchas, gestionClientes& clientes,
	GestionReserva& reservas, ReporteEstadisticas& reportes) {
	int opcion;
	do {
		cout << "\n===== CENTRO DEPORTIVO ZONA ACTIVA =====\n";
		cout << "1. Gestion de canchas\n";
		cout << "2. Gestion de clientes\n";
		cout << "3. Gestion de reservas\n";
		cout << "4. Gestion de listado de espera\n";
		cout << "5. Reportes y estadisticas\n";
		cout << "6. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			canchas.RegistrarCancha();
			break;
		case 2:
			clientes.registrarClientes();
			break;
		case 3:
			reservas.RegistrarReserva();
			break;
		case 4:
			cout << "(Modulo de listado de espera pendiente de otro integrante)\n";
			break;
		case 5:
			reportes.mostrarMenu();
			break;
		case 6:
			cout << "Saliendo del sistema...\n";
			break;
		default:
			cout << "Opcion invalida.\n";
		}
	} while (opcion != 6);
}

int main() {
	GestionCanchas canchas;
	gestionClientes clientes;
	GestionReserva reservas(&canchas, &clientes);
	ReporteEstadisticas reportes(&canchas, &clientes, &reservas);

	menuPrincipal(canchas, clientes, reservas, reportes);

	return 0;
}
