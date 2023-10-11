#pragma once
#include "GeneradorCuentas.h"
#include <string>
using namespace std;
class Cliente {
public:

	Cliente(string, string,string, double);
	~Cliente();
	void setSaldo(double);
	string getNombre();
	string getCedula();
	string getContrasena();
	double getSaldo();
	string toString();

	void setNumCuenta(GeneradorCuentas*);
	int getNumCuenta(); 

private: 
	int numeroCuenta; 
	string nombre;
	string cedula;
	string contrasena; // new
	double saldo;
};

