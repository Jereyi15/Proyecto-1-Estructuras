#include "Cliente.h"
#include <sstream>
Cliente::Cliente(string _nombre, string _cedula,string _contrasena, double _saldo) : nombre(_nombre), cedula(_cedula),contrasena(_contrasena), saldo(_saldo), numeroCuenta(0) {
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

string Cliente::getContrasena()
{
	return contrasena;
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
	s << "Cuenta bancaria: " << numeroCuenta << endl; // nuevo
	s << "Saldo actual del cliente: " << saldo << endl;
	s << "-------------------------" << endl;

	return s.str();
}
 //nuevos
void Cliente::setNumCuenta(GeneradorCuentas* gen) {
	gen->inicializar();
	numeroCuenta = gen->addNumeroCuenta();
}
int Cliente::getNumCuenta() {
	return numeroCuenta;
}