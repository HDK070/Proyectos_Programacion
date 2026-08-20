#pragma once
#include <iostream>
#include <sstream>
#include <string>

const int MAX = 50;
class cliente[MAX] {
private:
	string nombre;
	string telefono;
	int identificacion;

public:

	cliente();
	cliente(string nombre, string telefono, int identificacion);
	void menuCliente();
	void registrarCliente(string nombre, string telefono, int identificacion); 
	cliente buscarClienteXID(int identificacion);
	void mostrarReservaCliente(int identificacion);
	string listado();
	string toString() const;
	~cliente();


};

