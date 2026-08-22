#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "clientes.h"

using namespace std;


class listadoEspera{
private:
	int numConsecutivo;
	cliente* clientePtr;
	//cancha* canchaPtr;
	char franja;
	char estado;

public:
	listadoEspera();
	listadoEspera(int numConsecutivo, cliente* clientePtr,/*Cancha* canchaPtr,*/ char franja, char estado);



};

