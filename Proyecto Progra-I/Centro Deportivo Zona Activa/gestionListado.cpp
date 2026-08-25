#include "gestionListado.h"
#include <iostream>
#include <sstream>
#include <string>



gestionListado::gestionListado() {
	cantidad = 0;
}

void gestionListado::registrarCliente(cliente* clientePtr) {
		if (cantidadClientes < MAX) {
			string nombre, telefono;
			this->numConsecutivo = numConsecutivo;
			char franja;
			cout << "Ingrese el nombre del cliente: ";
			cin >> nombre;
			cout << "Ingrese el telefono del cliente: ";
			cin >> telefono;
			cout << "Ingrese la identificacion del cliente: ";
			cin >> identificacion;
			listadoEspera num[cantidadClientes+1] = new listadoEspera(numConsecutivo++, cliente* clientePtr,Cancha* canchaPtr,franja, char estado);
			cantidadClientes++;
		}
		else {
			cout << "No se pueden registrar mas clientes." << endl;
		}
	}
}
}
string listado();
string toString(int numConsecutivo);
bool existeDuplicado(cliente* clientePtr, Cancha* canchaPtr);

