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
	void RegistrarCancha();
	void MostrarCanchas();
	Cancha* BuscarCancha(string codigo);
	void mostrarDisponibilidad(string codigo);
	void modificarPrecio(string codigo, float nuevoPrecio);
	~GestionCanchas();
};