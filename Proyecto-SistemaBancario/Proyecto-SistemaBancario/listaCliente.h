#pragma once
#include "Cliente.h"
#include <list>
#include <vector>
#include <stack>

class listaCliente {

	//Para el historial de transacciones
	struct Transaccion {
		string tipo;
		int cuenta;
		string nombreCliente;
		double saldo;
		double monto;
		double saldoRestante;
		int cuentaTransferencia;
		int contador;
	};

private:
	list<Cliente*> clientes;
	stack<Transaccion> historialTransacciones;
	int contador1;

public:
	//Constructor
	listaCliente();

	//Gestion clientes
	void agregarCliente(Cliente*);
	void eliminarCliente(string);
	string mostrarCliente();

	void cambiarSalario(string, double);
	int posDigito(double, int);
	void OrdenamientoRadix();

	//Encontrar 
	bool encontrarCliente(string);
	bool encontrarClienteNum(int);
	Cliente* encontrarClienteObj(int);
	Cliente* encontrarClienteObj2(string);
	Cliente* recuperarCliente(string);

	bool hayClientes();
	string mostrarCedulas();
	int cantClientes();

	//Metodos de tranferencias
	void depositarSaldo(int, double);
	void retirarSaldo(int, double);
	bool verificarSaldoRetirar(int, double);
	string mostrarCuentasBancarias();
	bool transferenciaBancaria(int, Cliente*, double);

	//Historial de transacciones
	void agregarDeposito(int, string, double, double, double);
	void agregarRetiro(int, string, double, double, double);
	void agregarTransferencia(int, string, int, double, double, double);
	string mostrarHistorialTransacciones();
	
	//Para Deshacer
	void deshacerDeposito(int, int, Cliente*);
	void deshacerRetiro(int, int, Cliente*);
	void deshacerTransferencia(int, int, Cliente*, Cliente*);
	string mostrarDepositos();
	string mostrarRetiros();
	string mostrarTransferencias();
	int obtenerCuentaAso(int, int);




};

