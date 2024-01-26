#include <iostream>

// Variables globales.
double numero1 = 0;  // Almacena el primer n�mero para operaciones num�ricas.
double numero2 = 0;  // Almacena el segundo n�mero para operaciones num�ricas.
std::string cadena1 = "";  // Almacena la primera cadena para concatenaci�n.
std::string cadena2 = "";  // Almacena la segunda cadena para concatenaci�n.

// Funciones del men� principal.
void menu_principal() {
	// Muestra las opciones del men� principal.
	std::cout << "MENU PRINCIPAL" << std::endl;
	std::cout << "(1)  Operaciones con N�meros" << std::endl;
	std::cout << "(2)  Concatenar 2 cadenas." << std::endl;
	std::cout << "(s/S)  Salir" << std::endl;
}

void submenu_numeros() {
	// Muestra las opciones del submen� de operaciones num�ricas.
	std::cout << "SUBMENU OP NUMEROS" << std::endl;
	std::cout << "(1)  Suma de 2 n�meros." << std::endl;
	std::cout << "(2)  Divisi�n de 2 n�meros." << std::endl;
	std::cout << "(m/M)  Volver al Menu principal" << std::endl;
}

void operacion_suma() {
	// Realiza la operaci�n de suma con dos n�meros ingresados por el usuario.
	std::cout << "Ingrese el primer n�mero: ";
	std::cin >> numero1;
	std::cout << "Ingrese el segundo n�mero: ";
	std::cin >> numero2;
	double resultado = numero1 + numero2;
	std::cout << "La suma de " << numero1 << " y " << numero2 << " es: " << resultado << std::endl;
}

void operacion_division() {
	// Realiza la operaci�n de divisi�n con dos n�meros ingresados por el usuario.
	std::cout << "Ingrese el numerador: ";
	std::cin >> numero1;
	std::cout << "Ingrese el denominador: ";
	std::cin >> numero2;
	if (numero2 != 0) {
		double resultado = numero1 / numero2;
		std::cout << "La divisi�n de " << numero1 << " entre " << numero2 << " es: " << resultado << std::endl;
	} else {
		std::cout << "Error: No se puede dividir entre cero." << std::endl;
	}
}

// Programa principal.
int main() {
	while (true) {
		menu_principal();
		char opcion_principal;
		std::cout << "Seleccione una opci�n: ";
		std::cin >> opcion_principal;
		
		if (opcion_principal == '1') {
			while (true) {
				submenu_numeros();
				char opcion_subnumero;
				std::cout << "Seleccione una opci�n: ";
				std::cin >> opcion_subnumero;
				
				if (opcion_subnumero == '1') {
					operacion_suma();
				} else if (opcion_subnumero == '2') {
					operacion_division();
				} else if (tolower(opcion_subnumero) == 'm') {
					break;
				} else {
					std::cout << "Opci�n no v�lida. Int�ntelo de nuevo." << std::endl;
				}
			}
		} else if (opcion_principal == '2') {
			// Realiza la concatenaci�n de dos cadenas ingresadas por el usuario.
			std::cout << "Ingrese la primera cadena: ";
			std::cin >> cadena1;
			std::cout << "Ingrese la segunda cadena: ";
			std::cin >> cadena2;
			std::string resultado_concatenacion = cadena1 + cadena2;
			std::cout << "La concatenaci�n de las cadenas es: " << resultado_concatenacion << std::endl;
		} else if (tolower(opcion_principal) == 's') {
			// Sale del programa si el usuario elige la opci�n de salir.
			break;
		} else {
			std::cout << "Opci�n no v�lida. Int�ntelo de nuevo." << std::endl;
		}
	}
	
	return 0;
}
