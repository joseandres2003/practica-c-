#include <iostream>
using namespace std;

// Declaracion de variables globales
int n1, n2, num;

// Declaracion de funcion para determinar si un número es par o impar
bool par_impar(int num)
{
	return num % 2 == 0;
}

// Declaracion de funcion para ingresar dos numeros
void ingresar()
{
	cout << "Ingresar el primer numero:";
	cin >> n1;
	cout << "Ingresar el segundo numero:";
	cin >> n2;
}

// Declaración de funcion para sumar dos números
int sumar()
{
	return n1 + n2;
}

// Declaración de funcion para multiplicar dos números
int multiplicar()
{
	return n1 * n2;
}

int main()
{
	ingresar();
	
	// Determinar si el primer numero ingresado es par o impar
	if (par_impar(n1))
	{
		cout << "El primer numero ingresado es par." << endl;
	}
	else
	{
		cout << "El primer numero ingresado es impar." << endl;
	}
	
	// Determinar si el segundo numero ingresado es par o impar
	if (par_impar(n2))
	{
		cout << "El segundo numero ingresado es par." << endl;
	}
	else
	{
		cout << "El segundo numero ingresado es impar." << endl;
	}
	
	// Mostrar la suma y multiplicacion de los dos numeros ingresados
	cout << "Suma de los numeros: " << sumar() << endl;
	cout << "Multiplicacion de los numeros: " << multiplicar() << endl;
	
	return 0;
}
