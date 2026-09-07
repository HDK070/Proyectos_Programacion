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
	void registrarCliente(cliente* clientePtr, Cancha* canchaPtr, int posicionfranja);
	string listado();
	string toString(int numConsecutivo);
	bool existeDuplicado(cliente* clientePtr,Cancha* canchaPtr,int posicionfranja);
<<<<<<< HEAD
	bool hayEsperandoPara(Cancha* canchaPtr, int posicionFranja);
=======
	void cambiarEstado();
>>>>>>> 26cd56b1b56f8ca66d5565f3f62bdb431fe5c675

};

