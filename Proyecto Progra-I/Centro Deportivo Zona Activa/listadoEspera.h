#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "gestionClientes.h"
#include "GestionCanchas.h"
using namespace std;


class listadoEspera{
private:
	static int numConsecutivo;
	cliente* clientePtr;
	Cancha* canchaPtr;
	char franja;
	char estado;

public:
	listadoEspera();
	listadoEspera(int numConsecutivo, cliente* clientePtr,Cancha* canchaPtr, char franja, char estado);
	void setCliente(cliente* clientePtr);
	void setCancha(Cancha* canchaPtr);
	void setFranja(char franja);
	void setEstado(char estado);


};

