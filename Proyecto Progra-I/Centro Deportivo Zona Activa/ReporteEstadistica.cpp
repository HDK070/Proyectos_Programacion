#include "ReporteEstadistica.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;


static string horaDeFranja(int indice) {
	int horaInicio = 8 + indice;
	string hh = (horaInicio < 10 ? "0" : "") + to_string(horaInicio);
	return hh + ":00";
}

ReporteEstadisticas::ReporteEstadisticas(GestionCanchas* misCanchas, gestionClientes* misClientes,
	GestionReserva* misReservas) {
	this->misCanchas = misCanchas;
	this->misClientes = misClientes;
	this->misReservas = misReservas;
}



int ReporteEstadisticas::contarReservasActivasPorCancha(Cancha* cancha) {
	int contador = 0;
	for (int i = 0; i < misReservas->getContador(); i++) {
		Reserva* r = misReservas->obtenerReserva(i);
		if (r != nullptr && r->estaActiva() && r->getCancha() == cancha) contador++;
	}
	return contador;
}

int ReporteEstadisticas::contarReservasActivasPorCliente(cliente* c) {
	int contador = 0;
	for (int i = 0; i < misReservas->getContador(); i++) {
		Reserva* r = misReservas->obtenerReserva(i);
		if (r != nullptr && r->estaActiva() && r->getCliente() == c) contador++;
	}
	return contador;
}

void ReporteEstadisticas::pausar() {
	cout << "\nPresione ENTER para continuar...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

void ReporteEstadisticas::limpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}


void ReporteEstadisticas::reporteCanchaMasReservas() {
	cout << "\n===== CANCHA CON MAYOR CANTIDAD DE RESERVAS ACTIVAS =====\n";

	if (misCanchas->getContador() == 0) {
		cout << "No hay canchas registradas." << endl;
		return;
	}

	Cancha* canchaTop = nullptr;
	int maxReservas = -1;

	cout << left << setw(10) << "Codigo" << setw(15) << "Deporte"
		<< setw(20) << "Reservas activas" << endl;

	for (int i = 0; i < misCanchas->getContador(); i++) {
		Cancha* c = misCanchas->obtenerCancha(i);
		int total = contarReservasActivasPorCancha(c);
		cout << left << setw(10) << c->getCodigo() << setw(15) << c->getTipoDeporte()
			<< setw(20) << total << endl;

		if (total > maxReservas) {
			maxReservas = total;
			canchaTop = c;
		}
	}

	cout << "\n--- Resultado ---\n";
	if (canchaTop == nullptr || maxReservas <= 0) {
		cout << "Ninguna cancha tiene reservas activas todavia." << endl;
		return;
	}

	cout << "Cancha con mas reservas activas: " << canchaTop->getCodigo()
		<< " (" << canchaTop->getTipoDeporte() << ") con " << maxReservas
		<< " reserva(s) activa(s).\n";

	cout << "Detalle de sus reservas activas:\n";
	for (int i = 0; i < misReservas->getContador(); i++) {
		Reserva* r = misReservas->obtenerReserva(i);
		if (r != nullptr && r->estaActiva() && r->getCancha() == canchaTop) {
			cout << r->toString() << endl;
		}
	}
}


void ReporteEstadisticas::reporteClienteMasReservas() {
	cout << "\n===== CLIENTE CON MAYOR CANTIDAD DE RESERVAS ACTIVAS =====\n";

	if (misClientes->getCantidadClientes() == 0) {
		cout << "No hay clientes registrados." << endl;
		return;
	}

	cliente* clienteTop = nullptr;
	int maxReservas = -1;

	cout << left << setw(15) << "Identificacion" << setw(25) << "Nombre"
		<< setw(20) << "Reservas activas" << endl;

	for (int i = 0; i < misClientes->getCantidadClientes(); i++) {
		cliente* cl = misClientes->obtenerCliente(i);
		int total = contarReservasActivasPorCliente(cl);
		cout << left << setw(15) << cl->getIdentificacion()
			<< setw(25) << cl->getNombre()
			<< setw(20) << total << endl;

		if (total > maxReservas) {
			maxReservas = total;
			clienteTop = cl;
		}
	}

	cout << "\n--- Resultado ---\n";
	if (clienteTop == nullptr || maxReservas <= 0) {
		cout << "Ningun cliente tiene reservas activas todavia." << endl;
		return;
	}

	cout << "Cliente con mas reservas activas: " << clienteTop->getNombre()
		<< " (ID " << clienteTop->getIdentificacion() << ") con " << maxReservas
		<< " reserva(s) activa(s).\n";

	cout << "Detalle de sus reservas activas:\n";
	for (int i = 0; i < misReservas->getContador(); i++) {
		Reserva* r = misReservas->obtenerReserva(i);
		if (r != nullptr && r->estaActiva() && r->getCliente() == clienteTop) {
			cout << r->toString() << endl;
		}
	}
}


void ReporteEstadisticas::reporteIngresoTotal() {
	cout << "\n===== INGRESO TOTAL GENERADO POR RESERVAS ACTIVAS =====\n";

	if (misReservas->getContador() == 0) {
		cout << "No hay reservas registradas." << endl;
		return;
	}

	float total = 0.0f;
	int cantidadActivas = 0;

	cout << "Detalle de reservas activas que generan ingreso:\n";
	for (int i = 0; i < misReservas->getContador(); i++) {
		Reserva* r = misReservas->obtenerReserva(i);
		if (r != nullptr && r->estaActiva()) {
			cout << r->toString() << endl;
			total += r->getMonto();
			cantidadActivas++;
		}
	}

	cout << "\n--- Resultado ---\n";
	if (cantidadActivas == 0) {
		cout << "No hay reservas activas, por lo tanto el ingreso total es 0.\n";
		return;
	}
	cout << "Cantidad de reservas activas: " << cantidadActivas << endl;
	cout << "Ingreso total generado: " << fixed << setprecision(2) << total << endl;
}


void ReporteEstadisticas::reportePorcentajeOcupacion() {
	cout << "\n===== PORCENTAJE DE OCUPACION POR CANCHA =====\n";

	if (misCanchas->getContador() == 0) {
		cout << "No hay canchas registradas." << endl;
		return;
	}

	for (int i = 0; i < misCanchas->getContador(); i++) {
		Cancha* c = misCanchas->obtenerCancha(i);

		cout << "\nCancha " << c->getCodigo() << " (" << c->getTipoDeporte() << ")\n";
		cout << "Detalle de franjas horarias:\n";

		int ocupadas = 0, libres = 0, mantenimiento = 0;
		for (int f = 0; f < 12; f++) {
			char estado = c->getFranja(f);
			cout << " " << horaDeFranja(f) << "=" << estado;
			if ((f + 1) % 6 == 0) cout << endl;

			if (estado == 'O') ocupadas++;
			else if (estado == 'L') libres++;
			else if (estado == 'M') mantenimiento++;
		}
		cout << endl;

		double porcentaje = (ocupadas / 12.0) * 100.0;
		cout << "Franjas ocupadas: " << ocupadas << " | Libres: " << libres
			<< " | En mantenimiento: " << mantenimiento << " (de 12 totales)\n";
		cout << "Porcentaje de ocupacion: " << fixed << setprecision(1)
			<< porcentaje << "%\n";
	}
}


void ReporteEstadisticas::reporteHorasMayorMenorReservas() {
	cout << "\n===== HORAS CON MAYOR Y MENOR CANTIDAD DE RESERVAS =====\n";

	if (misReservas->getContador() == 0) {
		cout << "No hay reservas registradas." << endl;
		return;
	}

	int conteoPorHora[12];
	for (int i = 0; i < 12; i++) conteoPorHora[i] = 0;

	
	for (int i = 0; i < misReservas->getContador(); i++) {
		Reserva* r = misReservas->obtenerReserva(i);
		if (r == nullptr || !r->estaActiva()) continue;
		for (int f = 0; f < 12; f++) {
			if (r->incluyeFranja(f)) conteoPorHora[f]++;
		}
	}

	cout << "Detalle: cantidad de reservas activas por franja horaria\n";
	int maxCantidad = conteoPorHora[0];
	int minCantidad = conteoPorHora[0];
	for (int f = 0; f < 12; f++) {
		cout << " " << horaDeFranja(f) << " -> " << conteoPorHora[f] << " reserva(s)\n";
		if (conteoPorHora[f] > maxCantidad) maxCantidad = conteoPorHora[f];
		if (conteoPorHora[f] < minCantidad) minCantidad = conteoPorHora[f];
	}

	cout << "\n--- Resultado ---\n";
	cout << "Hora(s) con MAYOR cantidad de reservas (" << maxCantidad << "): ";
	for (int f = 0; f < 12; f++) {
		if (conteoPorHora[f] == maxCantidad) cout << horaDeFranja(f) << " ";
	}
	cout << endl;

	cout << "Hora(s) con MENOR cantidad de reservas (" << minCantidad << "): ";
	for (int f = 0; f < 12; f++) {
		if (conteoPorHora[f] == minCantidad) cout << horaDeFranja(f) << " ";
	}
	cout << endl;
}


void ReporteEstadisticas::mostrarMenu() {
	int opcion;
	do {
		limpiarPantalla();
		cout << "===== REPORTES Y ESTADISTICAS =====\n";
		cout << "1. Cancha con mayor cantidad de reservas activas\n";
		cout << "2. Cliente con mayor cantidad de reservas activas\n";
		cout << "3. Ingreso total generado por las reservas activas\n";
		cout << "4. Porcentaje de ocupacion de cada cancha\n";
		cout << "5. Horas con mayor y menor cantidad de reservas\n";
		cout << "6. Volver al menu principal\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			opcion = -1;
		}

		switch (opcion) {
		case 1: reporteCanchaMasReservas(); pausar(); break;
		case 2: reporteClienteMasReservas(); pausar(); break;
		case 3: reporteIngresoTotal(); pausar(); break;
		case 4: reportePorcentajeOcupacion(); pausar(); break;
		case 5: reporteHorasMayorMenorReservas(); pausar(); break;
		case 6: break;
		default:
			cout << "Opcion invalida. Intente de nuevo.\n";
			pausar();
		}
	} while (opcion != 6);
}
