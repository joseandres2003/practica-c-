#include<iostream>
#include<vector>

using namespace std;

// Función para ingresar números
void ingresarNumeros(vector<int> &numeros) {
	int n;
	cout << "Ingrese la cantidad de números: ";
	cin >> n;
	
	numeros.resize(n);
	
	cout << "Ingrese los números, separados por espacios:" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> numeros[i];
	}
}

// Función para sumar los números
int sumarNumeros(const vector<int> &numeros) {
	int suma = 0;
	for (int num : numeros) {
		suma += num;
	}
	return suma;
}

// Función para verificar si un número es primo
bool esPrimo(int numero) {
	if (numero <= 1) {
		return false;
	}
	for (int i = 2; i * i <= numero; ++i) {
		if (numero % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	vector<int> numeros;
	int opcion;
	
	do {
		// Mostrar el menú
		cout << "\nMENU\n";
		cout << "1. Ingresar números\n";
		cout << "2. Sumar los números\n";
		cout << "3. Verificar si un número es primo\n";
		cout << "0. Salir\n";
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			ingresarNumeros(numeros);
			break;
		case 2:
			if (numeros.empty()) {
				cout << "No hay números para sumar. Ingrese números primero." << endl;
			} else {
				cout << "La suma de los números es: " << sumarNumeros(numeros) << endl;
			}
			break;
		case 3: {
			int num;
			cout << "Ingrese el número a verificar: ";
			cin >> num;
			if (esPrimo(num)) {
				cout << num << " es un número primo." << endl;
			} else {
				cout << num << " no es un número primo." << endl;
			}
			break;
		}
		case 0:
			cout << "Saliendo del programa. ¡Hasta luego!" << endl;
			break;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
		
	} while (opcion != 0);
	
	return 0;
}
