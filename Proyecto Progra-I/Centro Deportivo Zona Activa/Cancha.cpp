#include "Cancha.h"
#include <iostream>
Cancha::Cancha(string Codigo, string TipoDeporte, float precio) {
	this->Codigo = Codigo;
	this->TipoDeporte = TipoDeporte;
	this->precio = precio;
	for (int i = 0; i < 12; i++) {
		franjas[i] = 'L'; // Inicializa todas las franjas como libres
	}
}
string Cancha::getCodigo() {
	return Codigo;
}
string  Cancha::getTipoDeporte() {
	return TipoDeporte;
}
float Cancha::getPrecio() {
	return precio;
}
char Cancha::getFranja(int posicion) {
	if (posicion >= 0 && posicion < 12) {
		return franjas[posicion];
	}
	else {
		return 'X'; // Retorna 'X' si la posición es inválida
	}
}
void Cancha::setPrecio(float precio) {
	if (precio < 0) {
		cout << "Error: El precio no puede ser negativo." << endl;
		return;
	}
	else {
		this->precio = precio;
	}
}
void Cancha::setFranja(int posicion, char estado) {
	if (posicion >= 0 && posicion < 12) {
		if (estado == 'M' && franjas[posicion] == 'O') {
			cout << "Error: No se puede marcar una franja ocupada en mantenimiento." << endl;
			return;
		}
		franjas[posicion] = estado;
	}
	else {
		cout << "Error: Posición inválida." << endl;
	}
}