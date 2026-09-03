#include <iostream>
#include "GestionCanchas.h"
#include "Utilidades.h"
GestionCanchas::GestionCanchas() {
	contador = 0;
	for (int i = 0; i < 10; i++) {
		canchas[i] = nullptr;
	}
}
string GestionCanchas::horafranjas(int indice) {
	int horaInicio = 8 + indice;
	string hh = (horaInicio < 10 ? "0" : "") + to_string(horaInicio);
	return hh + ":00";
}
void GestionCanchas::RegistrarCancha() {
	if (contador >= 10) {
		cout << "No se pueden registrar m"<<char(160)<<"s canchas." << endl;
		return;
	}
	string codigo, tipoDeporte;
	float precio; bool existe;
	//Verificacion para que el codigo sea unico
	do {
		cout << "Ingrese el c" << char(162) << "digo de la cancha : ";
		cin >> codigo;
		existe = (BuscarCancha(codigo) != nullptr);
		if (existe) {
			cout << "Ya existe una cancha con ese codigo. Intente nuevamente." << endl;
		}
	} while (existe);

	cout << "Ingrese el tipo de deporte: ";
	cin >> tipoDeporte;
	cout << "Ingrese el precio por hora: ";
	cin >> precio;
	canchas[contador] = new Cancha(codigo, tipoDeporte, precio);
	contador++;
	cout << "Cancha registrada exitosamente." << endl;
}

void GestionCanchas::MostrarCanchas() {
	if (contador == 0) {
		cout << "No hay canchas registradas." << endl;
		return;
	}
	for (int i = 0; i < contador; i++) {
		cout << "C"<<char(162)<<"digo: " << canchas[i]->getCodigo() << ", Tipo de Deporte : " << canchas[i]->getTipoDeporte() << ", Precio : " << canchas[i]->getPrecio() << endl;
	}
}
Cancha* GestionCanchas::BuscarCancha(string codigo) {
	for (int i = 0; i < contador; i++) {
		if (canchas[i]->getCodigo() == codigo) {
			return canchas[i];
		}
	}
	return nullptr;
}
void GestionCanchas::mostrarDisponibilidad(string codigo) {
	Cancha* cancha = BuscarCancha(codigo);
	if (cancha == nullptr) {
		cout << "Cancha no encontrada." << endl;
		return;
	}

	bool disponible = true;
	cout << "Disponibilidad de la cancha " << codigo << ":" << endl;
	for (int i = 0; i < 12; i++) {
		char estado = cancha->getFranja(i);
		cout << horafranjas(i) << ": " << estado << endl;;
	}

	if (disponible) {
		cout << "La cancha esta disponible." << endl;
	}
	else {
		cout << "La cancha no esta disponible." << endl;
	}
}
void GestionCanchas::modificarPrecio(string codigo, float nuevoPrecio) {
	Cancha* cancha = BuscarCancha(codigo);
	if (cancha != nullptr) {
		cancha->setPrecio(nuevoPrecio);
		cout << "Precio modificado exitosamente." << endl;
	}
	else {
		cout << "Cancha no encontrada." << endl;
	}
}

int GestionCanchas::getContador() {
	return contador;
}

Cancha* GestionCanchas::obtenerCancha(int indice) {
	if (indice < 0 || indice >= contador) {
		return nullptr;
	}
	return canchas[indice];
}

GestionCanchas::~GestionCanchas() {
	for (int i = 0; i < contador; i++) {
		delete canchas[i];
		canchas[i] = nullptr;
	}
}

void GestionCanchas::submenuGC() {
	int opcion;
	do {
		limpiarPantalla();
		cout << "\n===== GESTION DE CANCHAS =====\n";
		cout << "1. Registrar cancha\n";
		cout << "2. Mostrar todas las canchas\n";
		cout << "3. Buscar cancha por codigo\n";
		cout << "4. Modificar precio de una cancha\n";
		cout << "5. Mostrar disponibilidad de una cancha\n";
		cout << "6. Volver al men" << char(163) << " principal\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Entrada invalida." << endl;
			continue;
		}
		string codigo;
		float nuevoPrecio;

		switch (opcion) {
		case 1:
			RegistrarCancha(); pausar();
			break;
		case 2:
			MostrarCanchas(); pausar();
			break;
		case 3:
			cout << "Ingrese el codigo de la cancha a buscar: ";
			cin >> codigo;
			if (BuscarCancha(codigo) != nullptr) {
				cout << "Cancha encontrada (existente)\n";
			}
			else {
				cout << "Cancha no encontrada (inexistente)\n";
			}
			pausar();
			break;
		case 4:
			cout << "Ingrese el codigo de la cancha: ";
			cin >> codigo;
			cout << "\nIngrese el nuevo precio: ";
			cin >> nuevoPrecio;
			modificarPrecio(codigo, nuevoPrecio); pausar();
			break;
		case 5:
			cout << "Ingrese el codigo de la cancha: ";
			cin >> codigo;
			mostrarDisponibilidad(codigo); pausar();
			break;
		case 6:
			break;
		default:
			cout << "Opci" << char(162) << "n invalida." << endl;
		}
	} while (opcion != 6);
}
