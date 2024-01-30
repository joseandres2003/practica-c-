#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Vectores para almacenar datos
vector<string> nombres(10);
vector<string> apellidos(10);
vector<string> contraseñas(10);
vector<int> notas(10);

// Función para llenar nombres, apellidos y notas de forma aleatoria
void llenarDatosAleatorios() {
	for (int i = 0; i < 10; ++i) {
		cout << "Ingrese el nombre " << i + 1 << ": ";
		cin >> nombres[i];
		cout << "Ingrese el apellido " << i + 1 << ": ";
		cin >> apellidos[i];
		notas[i] = rand() % 30 + 1; // Nota aleatoria entre 1 y 30
	}
}

// Función para ofuscar nombres y apellidos para llenar las contraseñas
void ofuscarContraseñas() {
	for (int i = 0; i < 10; ++i) {
		contraseñas[i] = "";
		for (char c : nombres[i]) {
			switch (tolower(c)) {
			case 'a': contraseñas[i] += '4'; break;
			case 'e': contraseñas[i] += '3'; break;
			case 'i': contraseñas[i] += '1'; break;
			case 'o': contraseñas[i] += '0'; break;
			case 's': contraseñas[i] += '5'; break;
			case 't': contraseñas[i] += '7'; break;
			default: contraseñas[i] += c;
			}
		}
		for (char c : apellidos[i]) {
			switch (tolower(c)) {
			case 'a': contraseñas[i] += '4'; break;
			case 'e': contraseñas[i] += '3'; break;
			case 'i': contraseñas[i] += '1'; break;
			case 'o': contraseñas[i] += '0'; break;
			case 's': contraseñas[i] += '5'; break;
			case 't': contraseñas[i] += '7'; break;
			default: contraseñas[i] += c;
			}
		}
	}
}

// Función para calcular la media, el mayor y el menor de todas las notas
void calcularEstadisticasNotas() {
	double promedio = 0;
	int notaMaxima = notas[0];
	int notaMinima = notas[0];
	
	// Imprimir datos
	cout << "\nNombre\t\tApellido\tNota\tContraseña\n";
	for (int i = 0; i < 10; ++i) {
		cout << nombres[i] << "\t\t" << apellidos[i] << "\t\t" << notas[i] << "\t" << contraseñas[i] << "\n";
		promedio += notas[i];
		if (notas[i] > notaMaxima) {
			notaMaxima = notas[i];
		}
		if (notas[i] < notaMinima) {
			notaMinima = notas[i];
		}
	}
	
	promedio /= 10;
	
	// Imprimir estadísticas
	cout << "\nPromedio de nota es: " << promedio << "\n";
	cout << "\nMayor\n";
	imprimirDetalle(notaMaxima);
	cout << "\nMenor\n";
	imprimirDetalle(notaMinima);
}

// Función para imprimir detalles de una nota específica
void imprimirDetalle(int nota) {
	for (int i = 0; i < 10; ++i) {
		if (notas[i] == nota) {
			cout << nombres[i] << "\t\t" << apellidos[i] << "\t\t" << notas[i] << "\t" << contraseñas[i] << "\n";
		}
	}
}

int main() {
	srand(time(nullptr)); // Inicializar la semilla para números aleatorios
	
	while (true) {
		cout << "\nMENÚ Trabajo Practico 4\n";
		cout << "(1) – Llenar nombres, apellidos y notas de forma aleatoria.\n";
		cout << "(2) – Ofuscar nombres y apellidos para llenar las contraseñas.\n";
		cout << "(3) – Sacar la media, el mayor y menor de todas las notas.\n";
		cout << "(4) – Imprimir datos.\n";
		cout << "(s/S) – Salir\n";
		
		char opcion;
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			llenarDatosAleatorios();
			break;
		case '2':
			ofuscarContraseñas();
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
			cout << "Opción no válida. Intente de nuevo.\n";
		}
	}
	
	return 0;
}
