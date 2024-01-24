//REALIZAR UNA FUNCION BOOLEANO PARA RECIBIR UN PARAMTERO Y DETERMINAR SI ES PAR TRUE O IMPAR FALSE.
#include <iostream>

bool esPar(int numero) {
	return numero % 2 == 0;
}

int main() {
	int numero;
	std::cout << "Ingrese un número: ";
	std::cin >> numero;
	
	if (esPar(numero)) {
		std::cout << "El número es par." << std::endl;
	} else {
		std::cout << "El número es impar." << std::endl;
	}
	
	return 0;
}
