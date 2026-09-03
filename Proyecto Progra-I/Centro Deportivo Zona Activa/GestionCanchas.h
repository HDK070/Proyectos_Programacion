#pragma once
#include <string>
#include "Cancha.h"
using namespace std;

class GestionCanchas {
private:
	Cancha* canchas[10];
	int contador;
public:
	GestionCanchas();
	string horafranjas(int indice);
	void RegistrarCancha();
	void MostrarCanchas();
	Cancha* BuscarCancha(string codigo);
	void mostrarDisponibilidad(string codigo);
	void modificarPrecio(string codigo, float nuevoPrecio);
	int getContador();
	Cancha* obtenerCancha(int indice);
	~GestionCanchas();
	void submenuGC();
};