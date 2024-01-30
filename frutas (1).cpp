#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Vectores para almacenar datos
vector<string> nombres(10);
vector<string> apellidos(10);
vector<string> contrase�as(10);
vector<int> notas(10);

// Funci�n para llenar nombres, apellidos y notas de forma aleatoria
void llenarDatosAleatorios() {
	for (int i = 0; i < 10; ++i) {
		cout << "Ingrese el nombre " << i + 1 << ": ";
		cin >> nombres[i];
		cout << "Ingrese el apellido " << i + 1 << ": ";
		cin >> apellidos[i];
		notas[i] = rand() % 30 + 1; // Nota aleatoria entre 1 y 30
	}
}

// Funci�n para ofuscar nombres y apellidos para llenar las contrase�as
void ofuscarContrase�as() {
	for (int i = 0; i < 10; ++i) {
		contrase�as[i] = "";
		for (char c : nombres[i]) {
			switch (tolower(c)) {
			case 'a': contrase�as[i] += '4'; break;
			case 'e': contrase�as[i] += '3'; break;
			case 'i': contrase�as[i] += '1'; break;
			case 'o': contrase�as[i] += '0'; break;
			case 's': contrase�as[i] += '5'; break;
			case 't': contrase�as[i] += '7'; break;
			default: contrase�as[i] += c;
			}
		}
		for (char c : apellidos[i]) {
			switch (tolower(c)) {
			case 'a': contrase�as[i] += '4'; break;
			case 'e': contrase�as[i] += '3'; break;
			case 'i': contrase�as[i] += '1'; break;
			case 'o': contrase�as[i] += '0'; break;
			case 's': contrase�as[i] += '5'; break;
			case 't': contrase�as[i] += '7'; break;
			default: contrase�as[i] += c;
			}
		}
	}
}

// Funci�n para calcular la media, el mayor y el menor de todas las notas
void calcularEstadisticasNotas() {
	double promedio = 0;
	int notaMaxima = notas[0];
	int notaMinima = notas[0];
	
	// Imprimir datos
	cout << "\nNombre\t\tApellido\tNota\tContrase�a\n";
	for (int i = 0; i < 10; ++i) {
		cout << nombres[i] << "\t\t" << apellidos[i] << "\t\t" << notas[i] << "\t" << contrase�as[i] << "\n";
		promedio += notas[i];
		if (notas[i] > notaMaxima) {
			notaMaxima = notas[i];
		}
		if (notas[i] < notaMinima) {
			notaMinima = notas[i];
		}
	}
	
	promedio /= 10;
	
	// Imprimir estad�sticas
	cout << "\nPromedio de nota es: " << promedio << "\n";
	cout << "\nMayor\n";
	imprimirDetalle(notaMaxima);
	cout << "\nMenor\n";
	imprimirDetalle(notaMinima);
}

// Funci�n para imprimir detalles de una nota espec�fica
void imprimirDetalle(int nota) {
	for (int i = 0; i < 10; ++i) {
		if (notas[i] == nota) {
			cout << nombres[i] << "\t\t" << apellidos[i] << "\t\t" << notas[i] << "\t" << contrase�as[i] << "\n";
		}
	}
}

int main() {
	srand(time(nullptr)); // Inicializar la semilla para n�meros aleatorios
	
	while (true) {
		cout << "\nMEN� Trabajo Practico 4\n";
		cout << "(1) � Llenar nombres, apellidos y notas de forma aleatoria.\n";
		cout << "(2) � Ofuscar nombres y apellidos para llenar las contrase�as.\n";
		cout << "(3) � Sacar la media, el mayor y menor de todas las notas.\n";
		cout << "(4) � Imprimir datos.\n";
		cout << "(s/S) � Salir\n";
		
		char opcion;
		cout << "Seleccione una opci�n: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			llenarDatosAleatorios();
			break;
		case '2':
			ofuscarContrase�as();
			break;
		case '3':
			calcularEstadisticasNotas();
			break;
		case '4':
			// Imprimir datos
			calcularEstadisticasNotas();
			break;
		case 's':
		case 'S':
			return 0; // Salir del programa
		default:
			cout << "Opci�n no v�lida. Intente de nuevo.\n";
		}
	}
	
	return 0;
}
