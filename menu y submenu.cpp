#include <iostream>

// Variables globales.
double numero1 = 0;  // Almacena el primer número para operaciones numéricas.
double numero2 = 0;  // Almacena el segundo número para operaciones numéricas.
std::string cadena1 = "";  // Almacena la primera cadena para concatenación.
std::string cadena2 = "";  // Almacena la segunda cadena para concatenación.

// Funciones del menú principal.
void menu_principal() {
	// Muestra las opciones del menú principal.
	std::cout << "MENU PRINCIPAL" << std::endl;
	std::cout << "(1)  Operaciones con Números" << std::endl;
	std::cout << "(2)  Concatenar 2 cadenas." << std::endl;
	std::cout << "(s/S)  Salir" << std::endl;
}

void submenu_numeros() {
	// Muestra las opciones del submenú de operaciones numéricas.
	std::cout << "SUBMENU OP NUMEROS" << std::endl;
	std::cout << "(1)  Suma de 2 números." << std::endl;
	std::cout << "(2)  División de 2 números." << std::endl;
	std::cout << "(m/M)  Volver al Menu principal" << std::endl;
}

void operacion_suma() {
	// Realiza la operación de suma con dos números ingresados por el usuario.
	std::cout << "Ingrese el primer número: ";
	std::cin >> numero1;
	std::cout << "Ingrese el segundo número: ";
	std::cin >> numero2;
	double resultado = numero1 + numero2;
	std::cout << "La suma de " << numero1 << " y " << numero2 << " es: " << resultado << std::endl;
}

void operacion_division() {
	// Realiza la operación de división con dos números ingresados por el usuario.
	std::cout << "Ingrese el numerador: ";
	std::cin >> numero1;
	std::cout << "Ingrese el denominador: ";
	std::cin >> numero2;
	if (numero2 != 0) {
		double resultado = numero1 / numero2;
		std::cout << "La división de " << numero1 << " entre " << numero2 << " es: " << resultado << std::endl;
	} else {
		std::cout << "Error: No se puede dividir entre cero." << std::endl;
	}
}

// Programa principal.
int main() {
	while (true) {
		menu_principal();
		char opcion_principal;
		std::cout << "Seleccione una opción: ";
		std::cin >> opcion_principal;
		
		if (opcion_principal == '1') {
			while (true) {
				submenu_numeros();
				char opcion_subnumero;
				std::cout << "Seleccione una opción: ";
				std::cin >> opcion_subnumero;
				
				if (opcion_subnumero == '1') {
					operacion_suma();
				} else if (opcion_subnumero == '2') {
					operacion_division();
				} else if (tolower(opcion_subnumero) == 'm') {
					break;
				} else {
					std::cout << "Opción no válida. Inténtelo de nuevo." << std::endl;
				}
			}
		} else if (opcion_principal == '2') {
			// Realiza la concatenación de dos cadenas ingresadas por el usuario.
			std::cout << "Ingrese la primera cadena: ";
			std::cin >> cadena1;
			std::cout << "Ingrese la segunda cadena: ";
			std::cin >> cadena2;
			std::string resultado_concatenacion = cadena1 + cadena2;
			std::cout << "La concatenación de las cadenas es: " << resultado_concatenacion << std::endl;
		} else if (tolower(opcion_principal) == 's') {
			// Sale del programa si el usuario elige la opción de salir.
			break;
		} else {
			std::cout << "Opción no válida. Inténtelo de nuevo." << std::endl;
		}
	}
	
	return 0;
}
