#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "listadoEspera.h"
#include "gestionClientes.h"
#include "GestionCanchas.h"
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
	bool existeDuplicado(cliente* clientePtr, Cancha* canchaPtr, int posicionfranja);
	bool hayEsperandoPara(Cancha* canchaPtr, int posicionfranja);
	void cambiarEstado(int numConsecutivo, string nuevoEstado);
	void submenuGL(GestionCanchas* misCanchas, gestionClientes* misClientes);


};

