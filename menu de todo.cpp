#include<iostream>
#include<vector>

using namespace std;

// Funci�n para ingresar n�meros
void ingresarNumeros(vector<int> &numeros) {
	int n;
	cout << "Ingrese la cantidad de n�meros: ";
	cin >> n;
	
	numeros.resize(n);
	
	cout << "Ingrese los n�meros, separados por espacios:" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> numeros[i];
	}
}

// Funci�n para sumar los n�meros
int sumarNumeros(const vector<int> &numeros) {
	int suma = 0;
	for (int num : numeros) {
		suma += num;
	}
	return suma;
}

// Funci�n para verificar si un n�mero es primo
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
		// Mostrar el men�
		cout << "\nMENU\n";
		cout << "1. Ingresar n�meros\n";
		cout << "2. Sumar los n�meros\n";
		cout << "3. Verificar si un n�mero es primo\n";
		cout << "0. Salir\n";
		cout << "Ingrese su opci�n: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			ingresarNumeros(numeros);
			break;
		case 2:
			if (numeros.empty()) {
				cout << "No hay n�meros para sumar. Ingrese n�meros primero." << endl;
			} else {
				cout << "La suma de los n�meros es: " << sumarNumeros(numeros) << endl;
			}
			break;
		case 3: {
			int num;
			cout << "Ingrese el n�mero a verificar: ";
			cin >> num;
			if (esPrimo(num)) {
				cout << num << " es un n�mero primo." << endl;
			} else {
				cout << num << " no es un n�mero primo." << endl;
			}
			break;
		}
		case 0:
			cout << "Saliendo del programa. �Hasta luego!" << endl;
			break;
		default:
			cout << "Opci�n no v�lida. Intente de nuevo." << endl;
		}
		
	} while (opcion != 0);
	
	return 0;
}
