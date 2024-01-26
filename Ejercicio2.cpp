#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Prototipos de funciones
void generarNumeroAleatorio(int &numero);  // Prototipo de la función que genera un número aleatorio entre 0 y 500.
void generarNumeroAleatorioReal(double &numeroReal);  // Prototipo de la función que genera un número aleatorio real entre 0 y 1.
bool esPrimo(int numero);  // Prototipo de la función que verifica si un número es primo.
void generarNumerosPrimos(int N);  // Prototipo de la función que genera los primeros N números primos.

int main() {
	srand(time(0)); // Inicializar la semilla para generar números aleatorios diferentes en cada ejecución
	
	char opcion;
	int numero;
	double numeroReal;
	int N;
	
	do {
		cout << "\nMENU:\n";
		cout << "(1) Generar número aleatorio entre 0-500\n";
		cout << "(2) Generar número aleatorio real\n";
		cout << "(3) Generar N números primos\n";
		cout << "(s/S) Salir\n";
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			generarNumeroAleatorio(numero);
			cout << "Número aleatorio entre 0-500: " << numero << endl;
			break;
			
		case '2':
			generarNumeroAleatorioReal(numeroReal);
			cout << "Número aleatorio real: " << numeroReal << endl;
			break;
			
		case '3':
			cout << "Ingrese la cantidad de números primos a generar: ";
			cin >> N;
			generarNumerosPrimos(N);
			break;
			
		case 's':
		case 'S':
			cout << "Saliendo del programa. ¡Hasta luego!" << endl;
			break;
			
		default:
			cout << "Opción no válida. Inténtelo de nuevo." << endl;
		}
		
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}

void generarNumeroAleatorio(int &numero) {
	numero = rand() % 501; // Genera un número aleatorio entre 0 y 500
}

void generarNumeroAleatorioReal(double &numeroReal) {
	numeroReal = static_cast<double>(rand()) / RAND_MAX; // Genera un número real entre 0 y 1
}

bool esPrimo(int numero) {
	if (numero <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(numero); ++i) {
		if (numero % i == 0) {
			return false;
		}
	}
	return true;
}

void generarNumerosPrimos(int N) {
	cout << "Los primeros " << N << " números primos son:\n";
	int contador = 0;
	int numero = 2;
	
	while (contador < N) {
		if (esPrimo(numero)) {
			cout << numero << " ";
			++contador;
		}
		++numero;
	}
	
	cout << endl;
}
