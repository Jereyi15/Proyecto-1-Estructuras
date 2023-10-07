#include "Cliente.h"
#include <sstream>
Cliente::Cliente(string _nombre, string _cedula, double _saldo) : nombre(_nombre), cedula(_cedula), saldo(_saldo) {
}

Cliente::~Cliente()
{

}

void Cliente::setSaldo(double nuevoSaldo) {
	saldo = nuevoSaldo;
}

string Cliente::getNombre()
{
	return nombre;
}

string Cliente::getCedula()
{
	return cedula;
}

double Cliente::getSaldo()
{
	return saldo;
}

string Cliente::toString()
{
	stringstream s;

	s << "-------------------------" << endl;
	s << "Nombre del cliente: " << nombre << endl;
	s << "Cedula del cliente: " << cedula << endl;
	s << "Saldo actual del cliente: " << saldo << endl;
	s << "-------------------------" << endl;

	return s.str();
}