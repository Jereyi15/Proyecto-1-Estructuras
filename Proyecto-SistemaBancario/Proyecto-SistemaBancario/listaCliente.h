#pragma once
#include "Cliente.h"
#include <list>
#include <vector>

class listaCliente {
private:
	list<Cliente*> clientes;
public:
	void agregarCliente(Cliente*);
	void eliminarCliente(string);
	string mostrarCliente();
	void cambiarSalario(string, double);
	int posDigito(double, int);
	void OrdenamientoRadix();
	bool encontrarCliente(string);
	bool hayClientes();
	string mostrarCedulas();
	void depositarSaldo(string, double);
	void retirarSaldo(string, double);
	bool verificarSaldoRetirar(string, double);

};

