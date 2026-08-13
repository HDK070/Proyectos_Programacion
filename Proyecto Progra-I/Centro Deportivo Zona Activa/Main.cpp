#include <iostream>
#include <string>
void Menu() {
	int opcion;
	do {
		std::cout << "\tCENTRO DEPORTIVO ZONA ACTIVA" << std::endl;
		std::cout << "1. Gestion de Canchas" << std::endl;
		std::cout << "2. Gestion de Clientes" << std::endl;
		std::cout << "3. Gestion de Reservas" << std::endl;
		std::cout << "4. Gestion de listado de espera" << std::endl;
		std::cout << "5. Reportes y estadisticas" << std::endl;
		std::cout << "6. Salir" << std::endl;
		std::cout << "Ingrese su opcion: ";
		std::cin >> opcion;
		if (std::cin.fail()) { //Detecta si la entrada es invalida (no es un numero)
			std::cin.clear(); // reinicia el estado de error de cin
			std::cin.ignore(100, '\n'); // saca del buffer la entrada invalida
			std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
		}else if (opcion < 1 || opcion > 6) {
		std::cout << "Opcion invalida. Por favor, ingrese una opcion valida." << std::endl;
		}else {
		switch (opcion) {
		case 1:
			std::cout << "Opcion 1 seleccionada" << std::endl;
			break;
		case 2:
			std::cout << "Opcion 2 seleccionada" << std::endl;
			break;
		case 3:
			std::cout << "Opcion 3 seleccionada" << std::endl;
			break;
		case 4:
			std::cout << "Opcion 4 seleccionada" << std::endl;
			break;
		case 5:
			std::cout << "opcion 5 seleccionada" << std::endl;
			break;
		case 6:
			std::cout << "saliendo del programa..." << std::endl;
			break;
			}
		}
	} while (opcion != 6);
}
int main() {
	Menu();
	return 0;
}