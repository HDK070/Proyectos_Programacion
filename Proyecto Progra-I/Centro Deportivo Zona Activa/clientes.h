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
	cliente();
	cliente(string nombre, string telefono, int identificacion);
	~cliente();
	string getNombre() const;
	int getIdentificacion() const;
	string getTelefono() const;
	void setNombre(string nombre);
	void setTelefono(string telefono);
	void setIdentificacion(int identificacion);
	string toString();
	
};