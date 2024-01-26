#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Prototipos de funciones
void generarNumeroAleatorio(int &numero);  // Prototipo de la funci�n que genera un n�mero aleatorio entre 0 y 500.
void generarNumeroAleatorioReal(double &numeroReal);  // Prototipo de la funci�n que genera un n�mero aleatorio real entre 0 y 1.
bool esPrimo(int numero);  // Prototipo de la funci�n que verifica si un n�mero es primo.
void generarNumerosPrimos(int N);  // Prototipo de la funci�n que genera los primeros N n�meros primos.

int main() {
	srand(time(0)); // Inicializar la semilla para generar n�meros aleatorios diferentes en cada ejecuci�n
	
	char opcion;
	int numero;
	double numeroReal;
	int N;
	
	do {
		cout << "\nMENU:\n";
		cout << "(1) Generar n�mero aleatorio entre 0-500\n";
		cout << "(2) Generar n�mero aleatorio real\n";
		cout << "(3) Generar N n�meros primos\n";
		cout << "(s/S) Salir\n";
		cout << "Ingrese su opci�n: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			generarNumeroAleatorio(numero);
			cout << "N�mero aleatorio entre 0-500: " << numero << endl;
			break;
			
		case '2':
			generarNumeroAleatorioReal(numeroReal);
			cout << "N�mero aleatorio real: " << numeroReal << endl;
			break;
			
		case '3':
			cout << "Ingrese la cantidad de n�meros primos a generar: ";
			cin >> N;
			generarNumerosPrimos(N);
			break;
			
		case 's':
		case 'S':
			cout << "Saliendo del programa. �Hasta luego!" << endl;
			break;
			
		default:
			cout << "Opci�n no v�lida. Int�ntelo de nuevo." << endl;
		}
		
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}

void generarNumeroAleatorio(int &numero) {
	numero = rand() % 501; // Genera un n�mero aleatorio entre 0 y 500
}

void generarNumeroAleatorioReal(double &numeroReal) {
	numeroReal = static_cast<double>(rand()) / RAND_MAX; // Genera un n�mero real entre 0 y 1
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
	cout << "Los primeros " << N << " n�meros primos son:\n";
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
