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

		clientes.clear();//esto elimina temporalmente los elementos de la lista, ya que el funcionamiento radix ya encontró el orden
						// y elimina los valores para reacomodarlos en las listas de listasT, para luego devolverlas a la lista original ya ordenados

		for (const auto& listasTem : listasT) {
			for (const auto& cliente : listasTem) {
				clientes.push_back(cliente);
			}
		}
	}
}

// busca cliente, si lo encuentra retorna true
bool listaCliente::encontrarCliente(string cedula) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getCedula() == cedula) {
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