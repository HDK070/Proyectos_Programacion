#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "listadoEspera.h"
#include "gestionClientes.h"
#include "gestionCanchas.h"
using namespace std;


const int Maximo = 10;
class gestionListado{
	listadoEspera* num[Maximo];
	int cantidad=0;
public:

	gestionListado();
	~gestionListado();
	void registrarCliente(cliente* clientePtr, Cancha* canchaPtr);
	string listado();
	string toString(int numConsecutivo);
	bool existeDuplicado(cliente* clientePtr,Cancha* canchaPtr,int posicionfranja);

};

