#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "clientes.h"


const int MAX = 100;
class gestionClientes{
private:
	cliente* clientes[MAX];
	int cantidadClientes;

public:
	gestionClientes();
	void registrarClientes();
	string eliminarCliente(int identificacion);
	string listado();
	string toString(int identificacion);
};

