#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "gestionClientes.h"
#include "GestionCanchas.h"
using namespace std;


class listadoEspera{
private:
	int numConsecutivo;
	cliente* clientePtr;
	Cancha* canchaPtr;
	char franja;
	string estado;
	int posicionFranja;

public:
	listadoEspera();
	listadoEspera(int numConsecutivo, cliente* clientePtr,Cancha* canchaPtr, char franja, string estado,int posicionFranja);
	void setCliente(cliente* clientePtr);
	void setCancha(Cancha* canchaPtr);
	void setFranja(char franja);
	void setEstado(string estado);
	int getNumConsecutivo();
	cliente* getCliente();
	Cancha* getCancha();
	char getFranja();
	string getEstado();
	int getposicionFranja();
};

