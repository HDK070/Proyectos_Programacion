#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "listadoEspera.h"
using namespace std;


const int MAX = 10;
class gestionListado{
	listadoEspera num[MAX];
	int cantidad=0;
public:

	gestionListado();
	void registrarCliente(cliente* clientePtr);
	string listado();
	string toString(int numConsecutivo);
	bool existeDuplicado(cliente* clientePtr,Cancha* canchaPtr);

};

