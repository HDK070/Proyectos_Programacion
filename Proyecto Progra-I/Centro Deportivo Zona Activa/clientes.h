#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class cliente {
private:
	string nombre;
	string telefono;
	int identificacion;

public:

	cliente(string nombre, string telefono, int identificacion);
	void getNombre() const;
	void getIdentificacion() const;
	void getTelefono() const;
	string setNombre(string nombre);
	string setTelefono(string telefono);
	int setIdentificacion(int identificacion);
};

