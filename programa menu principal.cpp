#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int suma_cadena(const string& cadena) {
	size_t pos = 0;
	int resultado = 0;
	
	while (pos < cadena.length()) {
		string numero_str;
		while (pos < cadena.length() && isdigit(cadena[pos])) {
			numero_str += cadena[pos];
			pos++;
		}
		if (!numero_str.empty()) {
			resultado += stoi(numero_str);
		}
		pos++; // Ignorar el signo de más
	}
	
	return resultado;
}

string nombre_apellido(const string& cadena) {
	size_t espacio = cadena.find(' ');
	if (espacio != string::npos && espacio + 1 < cadena.length()) {
		string nombre = cadena.substr(0, espacio);
		string apellido = cadena.substr(espacio + 1);
		return apellido + " " + nombre;
	} else {
		return cadena;
	}
}

string ofuscar(const string& cadena) {
	string resultado = cadena;
	for (char& c : resultado) {
		switch (c) {
		case 'A': case 'a': c = '4'; break;
		case 'E': case 'e': c = '3'; break;
		case 'I': case 'i': c = '1'; break;
		case 'O': case 'o': c = '0'; break;
		case 'S': case 's': c = '5'; break;
		case 'T': case 't': c = '7'; break;
		}
	}
	return resultado;
}

int main() {
	while (true) {
		cout << "\nMENU PRINCIPAL" << endl;
		cout << "1 - String suma de una cadena" << endl;
		cout << "2 - String Nombre y Apellido" << endl;
		cout << "3 - String ofuscar" << endl;
		cout << "s/S - Salir" << endl;
		
		char opcion;
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1': {
			string cadena;
			cout << "Ingrese la cadena para la suma: ";
			cin >> cadena;
			int resultado = suma_cadena(cadena);
			cout << "Resultado de la suma: " << resultado << endl;
			break;
		}
		
		case '2': {
			string cadena;
			cin.ignore(); // Limpiar el buffer del teclado
			cout << "Ingrese el nombre y apellido: ";
			getline(cin, cadena);
			string resultado = nombre_apellido(cadena);
			cout << "Nombre y Apellido invertidos: " << resultado << endl;
			break;
		}
		
		case '3': {
			string cadena;
			cout << "Ingrese la cadena para ofuscar: ";
			cin >> cadena;
			string resultado = ofuscar(cadena);
			cout << "Cadena ofuscada: " << resultado << endl;
			break;
		}
		
		case 's':
		case 'S':
			return 0;
			
		default:
			cout << "Opción no válida. Inténtelo de nuevo." << endl;
		}
	}
	
	return 0;
}
