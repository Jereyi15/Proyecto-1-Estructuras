#pragma once
#include "GeneradorCuentas.h"
#include <string>
using namespace std;
class Cliente {
private:
	string nombre;
	string cedula;
	double saldo;

public:

	Cliente(string, string, double);
	~Cliente();
	void setSaldo(double);
	string getNombre();
	string getCedula();
	double getSaldo();
	string toString();

	void setNumCuenta(GeneradorCuentas*); //nuevo
	int getNumCuenta(); //nuevo

private: 
	int numeroCuenta; //nuevo
};

