#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "listadoEspera.h"
using namespace std;


const int MAX = 10;
class gestionListado{
	listadoEspera num[MAX];
	int cantidad;
public:

	gestionListado();
	void registrarListado(listadoEspera listado);
	string listado();
	string toString(int numConsecutivo);
	bool existeDuplicado(cliente* clientePtr/*cancha* canchaPtr*/);

};

