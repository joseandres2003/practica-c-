#include <iostream>
using namespace std;

// Declaraci�n de variables globales.
int n1, n2;

// Funci�n para sumar dos n�meros.
int sumar()
{
	return n1 + n2;
}

// Funci�n para multiplicar dos n�meros.
int multiplicacion()
{
	return n1 * n2;
}

// Funci�n para ingresar dos n�meros.
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
