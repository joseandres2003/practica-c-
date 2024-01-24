#include <iostream>
using namespace std;

// Declaración de variables globales.
int n1, n2;

// Función para sumar dos números.
int sumar()
{
	return n1 + n2;
}

// Función para multiplicar dos números.
int multiplicacion()
{
	return n1 * n2;
}

// Función para ingresar dos números.
void ingresar()
{
	cout << "Ingresar el primer numero:";
	cin >> n1;
	cout << "Ingresar el segundo numero:";
	cin >> n2;
}

int main(int argc, char *argv[])
{
	ingresar();
	cout << "Suma de los numeros es: " << sumar() << endl;
	cout << "Multiplicacion de los numeros es: " << multiplicacion() << endl;
	return 0;
}
