#include <iostream>
#include <string>

void Menu()  {
	int opcion;
	do {
		std::cout << "\tCENTRO DEPORTIVO ZONA ACTIVA" << endl;
		std::cout << "1. Gestion de Canchas" << endl;
		std::cout << "2. Gestion de Clientes" << endl;
		std::cout << "3. Gestion de Reservas" << endl;
		std::cout << "4. Gestion de listado de espera" << endl;
		std::cout << "5. Reportes y estadisticas" << endl;
		std::cout << "6. Salir" << endl;
		std::cout << "Ingrese su opcion: ";
		std::cin >> opcion;
		if (std::cin.fail()) { //Detecta si la entrada es invalida (no es un numero)
			std::cin.clear(); // reinicia el estado de error de std::cin
			std::cin.ignore(100, '\n'); // saca del buffer la entrada invalida
			std::cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
		}else if (opcion < 1 || opcion > 6) {
		std::cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
		}else {
		switch (opcion) {
		case 1:
			std::cout << "Opcion 1 seleccionada" << endl;
			break;
		case 2:
			std::cout << "Opcion 2 seleccionada" << endl;
			break;
		case 3:
			std::cout << "Opcion 3 seleccionada" << endl;
			break;
		case 4:
			std::cout << "Opcion 4 seleccionada" << endl;
			break;
		case 5:
			std::cout << "opcion 5 seleccionada" << endl;
			break;
		case 6:
			std::cout << "saliendo del programa..." << endl;
			break;
			}
		}
	} while (opcion != 6);
}
int main() {
	Menu();
	return 0;
}