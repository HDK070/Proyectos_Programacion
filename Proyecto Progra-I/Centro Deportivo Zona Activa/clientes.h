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
	string getNombre() const;
	string getTelefono() const;
	int getIdentificacion() const;
	



};

