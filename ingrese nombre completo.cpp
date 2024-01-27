#include <iostream>
#include <string>
#include <cctype>  // Necesario para la función toupper y tolower
using namespace std;

// Función para convertir la primera letra de cada palabra a mayúscula
string convertirAMayuscula(string palabra) {
	for (size_t i = 0; i < palabra.length(); ++i) {
		if (i == 0 || palabra[i - 1] == ' ') {
			palabra[i] = toupper(palabra[i]);
		} else {
			palabra[i] = tolower(palabra[i]);
		}
	}
	return palabra;
}

int main() {
	// Variable para almacenar el nombre completo
	string nombreCompleto;
	
	// Solicitar al usuario que ingrese su nombre completo
	cout << "Ingrese su nombre completo: ";
	getline(cin, nombreCompleto);  // Permitir espacios en blanco en el nombre
	
	// Encontrar el primer espacio que separa el nombre del apellido paterno
	size_t primerEspacio = nombreCompleto.find(' ');
	
	// Verificar si se encontró un espacio
	if (primerEspacio != string::npos) {
		// Extraer el nombre y el resto de la cadena
		string nombre = convertirAMayuscula(nombreCompleto.substr(0, primerEspacio));
		string apellidos = convertirAMayuscula(nombreCompleto.substr(primerEspacio + 1));
		
		// Encontrar el segundo espacio que separa el apellido paterno del apellido materno
		size_t segundoEspacio = apellidos.find(' ');
		
		// Verificar si se encontró un segundo espacio
		if (segundoEspacio != string::npos) {
			// Extraer el apellido paterno y materno
			string apellidoPaterno = convertirAMayuscula(apellidos.substr(0, segundoEspacio));
			string apellidoMaterno = convertirAMayuscula(apellidos.substr(segundoEspacio + 1));
			
			// Mostrar los resultados
			cout << "Nombre: " << nombre << endl;
			cout << "Apellido Paterno: " << apellidoPaterno << endl;
			cout << "Apellido Materno: " << apellidoMaterno << endl;
		} else {
			// Mostrar un mensaje de error si no se encuentra un segundo espacio
			cout << "Error: El nombre completo no contiene un segundo espacio para separar los apellidos." << endl;
		}
	} else {
		// Mostrar un mensaje de error si no se encuentra un primer espacio
		cout << "Error: El nombre completo no contiene un espacio para separar el nombre del apellido paterno." << endl;
	}
	
	return 0;
}
