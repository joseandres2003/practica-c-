//REALIZAR UNA FUNCION BOOLEANO PARA RECIBIR UN PARAMTERO Y DETERMINAR SI ES PAR TRUE O IMPAR FALSE.
#include <iostream>

bool esPar(int numero) {
	return numero % 2 == 0;
}

int main() {
	int numero;
	std::cout << "Ingrese un n�mero: ";
	std::cin >> numero;
	
	if (esPar(numero)) {
		std::cout << "El n�mero es par." << std::endl;
	} else {
		std::cout << "El n�mero es impar." << std::endl;
	}
	
	return 0;
}
