#include <iostream>
#include <limits> // para std::numeric_limits

using namespace std;

// Declaración de funciones
int suma(int num1, int num2) {
	return num1 + num2;
}

int main() {
	// Variables para almacenar los números ingresados por el usuario
	int numero1, numero2;
	
	// Solicitar al usuario que ingrese el primer numero
	cout << "Ingrese el primer numero: ";
	cin >> numero1; // Se debe usar el nombre correcto de la variable, que es numero1
	
	// Solicitar al usuario que ingrese el segundo numero
	cout << "Ingrese el segundo numero: ";
	cin >> numero2; // Se debe usar el nombre correcto de la variable, que es numero2
	
	// Calcular la suma utilizando la función suma
	int resultado = suma(numero1, numero2);
	
	// Mostrar el resultado de la suma
	cout << "La suma de " << numero1 << " y " << numero2 << " es: " << resultado << endl;
	
	return 0;
}
