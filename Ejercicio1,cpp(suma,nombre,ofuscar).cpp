#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Funci�n que realiza la suma de los n�meros presentes en una cadena
int suma_cadena(const string& cadena) {
	size_t pos = 0;
	int resultado = 0;
	
	// Iterar a trav�s de la cadena
	while (pos < cadena.length()) {
		string numero_str;
		// Construir el n�mero d�gito por d�gito
		while (pos < cadena.length() && isdigit(cadena[pos])) {
			numero_str += cadena[pos];
			pos++;
		}
		// Si se encontr� un n�mero, sumarlo al resultado
		if (!numero_str.empty()) {
			resultado += stoi(numero_str);
		}
		pos++; // Ignorar el signo de m�s
	}
	
	return resultado;
}

// Funci�n que intercambia el nombre y el apellido, con la primera letra en may�scula
string nombre_apellido(const string& cadena) {
	size_t primer_espacio = cadena.find(' ');
	if (primer_espacio != string::npos && primer_espacio + 1 < cadena.length()) {
		// Encontrar el segundo espacio a partir del primer espacio
		size_t segundo_espacio = cadena.find(' ', primer_espacio + 1);
		if (segundo_espacio == string::npos) {
			segundo_espacio = cadena.length();
		}
		
		string nombre = cadena.substr(0, primer_espacio);
		string apellido1 = cadena.substr(primer_espacio + 1, segundo_espacio - primer_espacio - 1);
		string apellido2 = cadena.substr(segundo_espacio + 1);
		
		// Convertir la primera letra del nombre a may�scula
		if (!nombre.empty()) {
			nombre[0] = toupper(nombre[0]);
		}
		
		// Convertir la primera letra de ambos apellidos a may�scula
		if (!apellido1.empty()) {
			apellido1[0] = toupper(apellido1[0]);
		}
		
		if (!apellido2.empty()) {
			apellido2[0] = toupper(apellido2[0]);
		}
		
		// Devolver la cadena invertida
		return apellido1 + " " + apellido2 + " " + nombre;
	} else {
		return cadena;
	}
}

// Funci�n que ofusca ciertos caracteres en la cadena
string ofuscar(const string& cadena) {
	string resultado = cadena;
	// Reemplazar caracteres espec�ficos por otros
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
		// Men� principal
		cout << "\nMENU PRINCIPAL" << endl;
		cout << "1 - String suma de una cadena" << endl;
		cout << "2 - String Nombre y Apellido" << endl;
		cout << "3 - String ofuscar" << endl;
		cout << "s/S - Salir" << endl;
		
		char opcion;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1': {
			// Opci�n para la suma de n�meros en una cadena
			string cadena;
			cout << "Ingrese la cadena para la suma: ";
			cin >> cadena;
			int resultado = suma_cadena(cadena);
			cout << "Resultado de la suma: " << resultado << endl;
			break;
		}
		
		case '2': {
			// Opci�n para invertir nombre y apellido con la primera letra en may�scula
			string cadena;
			cin.ignore(); // Limpiar el buffer del teclado
			cout << "Ingrese el nombre y apellidos: ";
			getline(cin, cadena);
			string resultado = nombre_apellido(cadena);
			cout << "Nombre y Apellidos invertidos: " << resultado << endl;
			break;
		}
		
		case '3': {
			// Opci�n para ofuscar ciertos caracteres en una cadena
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
			cout << "Opcion no v�lida. Int�ntelo de nuevo." << endl;
		}
	}
	
	return 0;
}
