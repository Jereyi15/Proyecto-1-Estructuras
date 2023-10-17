#include "listaCliente.h"
#include <sstream>
using namespace std;

listaCliente::listaCliente() : contador1(0) {}

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
Cliente* listaCliente::encontrarClienteObj(int cuenta) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getNumCuenta() == cuenta) {
			return (*i);
		}
	}
	return nullptr;
}

Cliente* listaCliente::encontrarClienteObj2(string cedula) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getCedula() == cedula) {
			return (*i);
		}
	}
	return nullptr;
}
// retorna true si se encontraron clientes en la lista
bool listaCliente::hayClientes() {
	if (clientes.size() > 0) {
		return true;
	}
	return false;
}

int listaCliente::cantClientes() {
	int size = clientes.size();
	return size;
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

			double saldoA = (*i)->getSaldo();

			(*i)->setSaldo((*i)->getSaldo() + deposito);

			//Se agrega la transaccion a el historial
			string nombre = (*i)->getNombre();
			double saldoR = (*i)->getSaldo();
			agregarDeposito(cuenta, nombre, deposito, saldoA, saldoR);
		}
	}
}

// retira saldo segun la cedula digitada //actualizado
void listaCliente::retirarSaldo(int cuenta, double deposito) {
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getNumCuenta() == cuenta) {

			double saldoA = (*i)->getSaldo();

			(*i)->setSaldo((*i)->getSaldo() - deposito);

			//Se agrega la transaccion a el historial
			string nombre = (*i)->getNombre();
			double saldoR = (*i)->getSaldo();
			agregarRetiro(cuenta, nombre, deposito, saldoA, saldoR);

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

			double saldoA = (*i)->getSaldo(); //usado para el historial

			double saldo = (*i)->getSaldo();
			double saldoNuevo;
			if (verificarSaldoRetirar(cuenta, saldo) == true) {
				saldo -= monto; //Se le resta la cantidad que transfiere
				(*i)->setSaldo(saldo);


				saldoNuevo = clienteTransferir->getSaldo();
				saldoNuevo += monto;
				clienteTransferir->setSaldo(saldoNuevo); //Se le setea el saldo nuevo al cliente transferido

				string nombre = (*i)->getNombre();
				double saldoR = (*i)->getSaldo();
				int cuentaTrans = clienteTransferir->getNumCuenta();
				agregarTransferencia(cuenta, nombre, cuentaTrans, monto, saldoA, saldoR);

				return true; //indica que la transferencia se hizo correctamente
			}
			else {
				return false; //no hay suficientes fondos
			}

		}
	}
}
Cliente* listaCliente::recuperarCliente(string cedula)
{
	Cliente* a = nullptr;
	for (auto i = clientes.begin(); i != clientes.end(); i++) {
		if ((*i)->getCedula() == cedula) {
			return *i;
		}
	}
	return nullptr;
}
// Metodos para el historial de transacciones
void listaCliente::agregarDeposito(int cuenta, string nombre, double monto, double saldoAntes, double saldoDesp) {
	Transaccion transaccion;
	contador1++;
	transaccion.tipo = "Deposito";
	transaccion.cuenta = cuenta;
	transaccion.nombreCliente = nombre;
	transaccion.monto = monto;
	transaccion.saldo = saldoAntes;
	transaccion.cuentaTransferencia = 0;
	transaccion.saldoRestante = saldoDesp;
	transaccion.contador = contador1;
	historialTransacciones.push(transaccion);
}
void listaCliente::agregarRetiro(int cuenta, string nombre, double monto, double saldoAntes, double saldoDesp) {
	Transaccion transaccion;
	contador1++;
	transaccion.tipo = "Retiro";
	transaccion.cuenta = cuenta;
	transaccion.nombreCliente = nombre;
	transaccion.monto = monto;
	transaccion.saldo = saldoAntes;
	transaccion.saldoRestante = saldoDesp;
	transaccion.cuentaTransferencia = 0;
	transaccion.contador = contador1;
	historialTransacciones.push(transaccion);
}
void listaCliente::agregarTransferencia(int cuenta, string nombre, int cuentaAsociada, double monto, double saldoAntes, double saldoDesp) {
	Transaccion transaccion;
	contador1++;
	transaccion.tipo = "Transferencia";
	transaccion.cuenta = cuenta;
	transaccion.nombreCliente = nombre;
	transaccion.cuentaTransferencia = cuentaAsociada;
	transaccion.monto = monto;
	transaccion.saldo = saldoAntes;
	transaccion.saldoRestante = saldoDesp;
	transaccion.contador = contador1;
	historialTransacciones.push(transaccion);
}
void listaCliente::deshacerDeposito(int cuenta, int contador, Cliente* cliente) {
	stack<Transaccion> aux = historialTransacciones;
	contador1++;
	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		if (transaccion.contador == contador && transaccion.cuenta == cuenta) {
			double deposito = transaccion.monto; //Se accede al monto que se deposito
			double SaldoA = cliente->getSaldo(); //Accedemos al saldo que tiene actualmente
			double SaldoR = cliente->getSaldo() - deposito; //Le restamos el monto que había depositado
			
			//Actualizamos los datos relevantes
			transaccion.monto = deposito;
			transaccion.saldo = SaldoA;
			transaccion.saldoRestante = SaldoR;
			transaccion.contador = contador1;

			//Actualizamos atributos del cliente
			cliente->setSaldo(SaldoR);

			historialTransacciones.push(transaccion);

		}
		aux.pop();
	}
}
void listaCliente::deshacerRetiro(int cuenta, int contador, Cliente* cliente) {
	stack<Transaccion> aux = historialTransacciones;
	contador1++;
	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		if (transaccion.contador == contador && transaccion.cuenta == cuenta) {
			double retiro = transaccion.monto; //Se accede al monto que se retiro
			double SaldoA = cliente->getSaldo(); //Accedemos al saldo que tiene actualmente
			double SaldoR = cliente->getSaldo() + retiro; //Le restamos el monto que había depositado el cual va a ser el saldo restante

			//Actualizamos los datos relevantes
			transaccion.monto = retiro;
			transaccion.saldo = SaldoA;
			transaccion.saldoRestante = SaldoR;
			transaccion.contador = contador1;

			//Actualizamos atributos del cliente
			cliente->setSaldo(SaldoR);

			historialTransacciones.push(transaccion);
		}
		aux.pop();
	}
}
void listaCliente::deshacerTransferencia(int cuenta, int contador, Cliente* cliente, Cliente* cliente2) {
	stack<Transaccion> aux = historialTransacciones;
	contador1++;
	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		if (transaccion.contador == contador && transaccion.cuenta == cuenta) {
			double transferencia = transaccion.monto;
			double SaldoA = cliente->getSaldo(); //Se accede al saldo que tenia en el momento
			double SaldoR = cliente->getSaldo() + transferencia; //Se le suma el monto que había transferido

			transaccion.monto = transferencia;
			transaccion.saldo = SaldoA;
			transaccion.saldoRestante = SaldoR;
			transaccion.contador = contador1;

			//Actualizamos atributos del cliente
			cliente->setSaldo(SaldoR);
			double SaldoR2 = cliente2->getSaldo() - transferencia;
			cliente2->setSaldo(SaldoR2);
		
			historialTransacciones.push(transaccion);

		}
		aux.pop();
	}
}
string listaCliente::mostrarHistorialTransacciones() {
	stack<Transaccion> aux = historialTransacciones;

	stringstream s;
	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		s << endl << "--------------------" << endl;
		s << "Tipo: " << transaccion.tipo << endl;
		s << "Cuenta: " << transaccion.cuenta << endl;
		s << "Nombre Cliente: " << transaccion.nombreCliente << endl;
		s << "Saldo Anterior: " << transaccion.saldo << endl;
		s << "Monto: " << transaccion.monto << endl;
		s << "Saldo Restante: " << transaccion.saldoRestante << endl;
		s << "Cuenta transferida: " << transaccion.cuentaTransferencia << endl;
		s << "Numero de transaccion: " << transaccion.contador << endl;
		s << "--------------------" << endl << endl;

		aux.pop();
	}
	return s.str();
}
string listaCliente::mostrarDepositos() {
	stack<Transaccion> aux = historialTransacciones; // Hacer una copia de la pila
	stringstream s;

	s << endl << "--------------------" << endl;
	s << endl << "Historial de Depositos" << endl;
	s << endl << "--------------------" << endl;

	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		if (transaccion.tipo == "Deposito") {
			s << endl << "--------------------" << endl;
			s << "Tipo: " << transaccion.tipo << endl;
			s << "Cuenta: " << transaccion.cuenta << endl;
			s << "Nombre Cliente: " << transaccion.nombreCliente << endl;
			s << "Saldo Anterior: " << transaccion.saldo << endl;
			s << "Monto: " << transaccion.monto << endl;
			s << "Saldo Restante: " << transaccion.saldoRestante << endl;
			s << "Cuenta de Transferencia: " << transaccion.cuentaTransferencia << endl;
			s << "Numero de transaccion: " << transaccion.contador << endl;
			s << "--------------------" << endl << endl;
		}
		aux.pop();
	}
	return s.str();
}
string listaCliente::mostrarRetiros() {
	stack<Transaccion> aux = historialTransacciones; // Hacer una copia de la pila
	stringstream s;

	s << endl << "--------------------" << endl;
	s << endl << "Historial de Retiros" << endl;
	s << endl << "--------------------" << endl;

	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		if (transaccion.tipo == "Retiro") {
			s << endl << "--------------------" << endl;
			s << "Tipo: " << transaccion.tipo << endl;
			s << "Cuenta: " << transaccion.cuenta << endl;
			s << "Nombre Cliente: " << transaccion.nombreCliente << endl;
			s << "Saldo Anterior: " << transaccion.saldo << endl;
			s << "Monto: " << transaccion.monto << endl;
			s << "Saldo Restante: " << transaccion.saldoRestante << endl;
			s << "Cuenta de Transferencia: " << transaccion.cuentaTransferencia << endl;
			s << "Numero de transaccion: " << transaccion.contador << endl;
			s << "--------------------" << endl << endl;
		}
		aux.pop();
	}
	return s.str();
}
string listaCliente::mostrarTransferencias() {
	stack<Transaccion> aux = historialTransacciones; // Hacer una copia de la pila
	stringstream s;

	s << endl << "--------------------" << endl;
	s << endl << "Historial de Transferencias" << endl;
	s << endl << "--------------------" << endl;

	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		if (transaccion.tipo == "Transferencia") {
			s << endl << "--------------------" << endl;
			s << "Tipo: " << transaccion.tipo << endl;
			s << "Cuenta: " << transaccion.cuenta << endl;
			s << "Nombre Cliente: " << transaccion.nombreCliente << endl;
			s << "Saldo Anterior: " << transaccion.saldo << endl;
			s << "Monto: " << transaccion.monto << endl;
			s << "Saldo Restante: " << transaccion.saldoRestante << endl;
			s << "Cuenta de Transferencia: " << transaccion.cuentaTransferencia << endl;
			s << "Numero de transaccion: " << transaccion.contador << endl;
			s << "--------------------" << endl << endl;
		}
		aux.pop();
	}
	return s.str();
}
int listaCliente::obtenerCuentaAso(int cuenta, int contador) {
	stack<Transaccion> aux = historialTransacciones;

	while (!aux.empty()) {
		Transaccion transaccion = aux.top();
		if (transaccion.contador == contador && transaccion.cuenta == cuenta) {
			int cuentaAso = transaccion.cuentaTransferencia;
			return cuentaAso;
		}
		aux.pop();
	}
}