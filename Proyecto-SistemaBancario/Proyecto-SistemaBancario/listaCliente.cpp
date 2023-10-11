#include "listaCliente.h"
#include <sstream>
using namespace std;
void listaCliente::agregarCliente(Cliente* cliente) {
	clientes.push_back(cliente);//Esto agrega el elemento al final de la lista
}

void listaCliente::eliminarCliente(string ced) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {//el end se utiliza para obtener un iterador al inicio de la lista, el end es lo contrario, obtiene el ultimo elemento
		if ((*i)->getCedula() == ced) {
			i = clientes.erase(i);//esto elimina los elementos de la lista enlazada
			return;
		}
	}
}

string listaCliente::mostrarCliente() {
	stringstream s;
	for (const auto& cliente : clientes) {
		s << (cliente)->toString() << endl;
	}
	return s.str();
}

void listaCliente::cambiarSalario(string ced, double nuevoSalario) {
	for (auto& cliente : clientes) { //este bucle for sirve para leer toda la lsita, usando la funcion "auto" se cambia el tipo de variable directamente
		if ((cliente)->getCedula() == ced) {
			cliente->setSaldo(nuevoSalario);
			return;
		}
	}
}

int listaCliente::posDigito(double num, int pos)
{
	int factor = 1;
	for (int i = 0; i < pos; i++) {
		factor *= 10;
	}
	return static_cast<int>(num / factor) % 10;
}

void listaCliente::OrdenamientoRadix() {
	int maxDig = 0;
	int digitos;
	for (const auto& cliente : clientes) {
		digitos = to_string(cliente->getSaldo()).length();
		if (digitos > maxDig) {
			maxDig = digitos;
		}
	}
	for (int i = 0; i < maxDig; i++) {
		vector<list<Cliente*>>listasT(10);//El vector listasT crea un vector de 10 listas, se usa el numero 10 porque se van a acomodar  dependiendo su salario, y este se encuentra en numeros decimales

		for (const auto& cliente : clientes) {
			int digito = posDigito(cliente->getSaldo(), i);
			listasT[9 - digito].push_back(cliente);//aqui se decide la manera de ordenar, ya sea descendente o ascendente
		}

		clientes.clear();//esto elimina temporalmente los elementos de la lista, ya que el funcionamiento radix ya encontr� el orden
						// y elimina los valores para reacomodarlos en las listas de listasT, para luego devolverlas a la lista original ya ordenados

		for (const auto& listasTem : listasT) {
			for (const auto& cliente : listasTem) {
				clientes.push_back(cliente);
			}
		}
	}
}

// busca cliente, si lo encuentra retorna true //actualizado
bool listaCliente::encontrarCliente(string cedula) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getCedula() == cedula) {
			return true;
		}
	}
	return false;
}
bool listaCliente::encontrarClienteNum(int cuenta) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getNumCuenta() == cuenta) {
			return true;
		}
	}
	return false;
}

// retorna true si se encontraron clientes en la lista
bool listaCliente::hayClientes() {
	if (clientes.size() > 0) {
		return true;
	}
	return false;
}

// muestra todas las cedulas
string listaCliente::mostrarCedulas() {
	stringstream s;
	for (const auto& it : clientes) {
		s << (it)->getCedula() << endl;
	}
	return s.str();
}

// deposita saldo segun la cedula digitada //actualizado
void listaCliente::depositarSaldo(int cuenta, double deposito) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getNumCuenta() == cuenta) {
			(*i)->setSaldo((*i)->getSaldo() + deposito);
			return;
		}
	}
}

// retira saldo segun la cedula digitada //actualizado
void listaCliente::retirarSaldo(int cuenta, double deposito) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getNumCuenta() == cuenta) {
			(*i)->setSaldo((*i)->getSaldo() - deposito);
			return;
		}
	}
}

// verifica que el saldo a retirar sea menor al saldo que posee el cliente //actualizado 
bool listaCliente::verificarSaldoRetirar(int cuenta, double saldoRetirar) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getNumCuenta() == cuenta) {
			double saldoCliente = (*i)->getSaldo();
			if (saldoRetirar <= saldoCliente) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}
// nuevo
// muestra todas las  cuentas bancarias disponibles
string listaCliente::mostrarCuentasBancarias() {
	stringstream s;
	for (const auto& it : clientes) {
		s << (it)->getNumCuenta() << endl;
	}
	return s.str();
}
//nuevo
bool listaCliente::transferenciaBancaria(int cuenta, Cliente* clienteTransferir, double monto) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getNumCuenta() == cuenta) {
			double saldo = (*i)->getSaldo();
			double saldoNuevo;
			if (verificarSaldoRetirar(cuenta, saldo) == true) {
				saldo -= monto; //Se le resta la cantidad que transfiere
				(*i)->setSaldo(saldo);
				saldoNuevo = clienteTransferir->getSaldo();
				saldoNuevo += monto; 
				clienteTransferir->setSaldo(saldoNuevo); //Se le setea el saldo nuevo al cliente transferido
				return true; //indica que la transferencia se hizo correctamente
			}
			else {
				return false; //no hay suficientes fondos
			}
			
		}
	}
}
