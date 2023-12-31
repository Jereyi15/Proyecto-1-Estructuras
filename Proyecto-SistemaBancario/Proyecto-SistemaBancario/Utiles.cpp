#include "Utiles.h"

#include <sstream>

Utiles::Utiles() {
}

Utiles::~Utiles() {
}

//Este m�todo valida si la opci�n es un entero
int Utiles::validarEntero() {
	int opcion = 0;
	bool estado = false;
	while (estado == false) {
		if (!(cin >> opcion)) {
			cout << "-----------------------------------\n";
			cout << "La opcion debe ser un valor entero.";
			cout << "\n-----------------------------------";
			cin.clear();
			cout << "\nDigite de nuevo la opcion: ";
		}
		else {
			estado = true;
		}
		cin.ignore(1000, '\n');
	}
	return opcion;
}

//Este m�todo valida si la entrada es de un double
double Utiles::validarDecimal() {
	double entrada = 0.0;
	bool estado = false;
	while (estado == false) {
		if (!(cin >> entrada)) {
			cout << "-------------------------------------\n";
			cout << "La entrada debe ser un valor decimal.";
			cout << "\n-------------------------------------";
			cin.clear();
			cout << "\nDigite nuevamente: ";
		}
		else {
			estado = true;
		}
		cin.ignore(1000, '\n');
	}
	return entrada;
}

//Este m�todo solo env�a un mensaje de que la opci�n es invalida
string Utiles::opcionInvalida() {
	stringstream s;

	s << "------------------------------------------------\n";
	s << "Entrada invalida. Por favor, intenta nuevamente.\n";
	s << "------------------------------------------------\n";

	return s.str();
}