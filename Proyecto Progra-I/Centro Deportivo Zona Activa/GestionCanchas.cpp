#include <iostream>
#include "GestionCanchas.h"

GestionCanchas::GestionCanchas() {
	contador = 0;
	for (int i = 0; i < 10; i++) {
		canchas[i] = nullptr;
	}
}

void GestionCanchas::RegistrarCancha() {
	if (contador >= 10) {
		cout << "No se pueden registrar más canchas." << endl;
		return;
	}
	string codigo, tipoDeporte;
	float precio;
	cout << "Ingrese el código de la cancha: ";
	cin >> codigo;
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
		cout << "Código: " << canchas[i]->getCodigo() << ", Tipo de Deporte: " << canchas[i]->getTipoDeporte() << ", Precio: " << canchas[i]->getPrecio() << endl;
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
		cout << "Franja " << i << ": ";

		switch (estado) {
		case 'L':
			cout << "Libre";
			break;
		case 'O':
			cout << "Ocupada";
			disponible = false;
			break;
		case 'M':
			cout << "Mantenimiento";
			disponible = false;
			break;
		}
		cout << endl;
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