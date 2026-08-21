#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "clientes.h"
using namespace std;

const int MAX = 100;
class gestionClientes{
private:

	cliente* clientes[MAX];
	int tam;
	int cantidadClientes;

public:
	gestionClientes();
	string registrarClientes();
	string eliminarCliente(int identificacion);
	string listado();
	string toString(int identificacion);
};

