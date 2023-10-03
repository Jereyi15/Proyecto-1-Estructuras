#include "Interfaz.h"
int main() {
	Interfaz* i = new Interfaz();
	i->iniciar();
	delete i;
	/* Colocar en Interfaz, ya que no sé si se va a iniciar con clientes, o crear todos los clientes desde la opción en el menu

	listaCliente* lista = new listaCliente();

	Cliente* c1 = new Cliente("Alfredo", "2086757976", 50000.0);
	Cliente* c2 = new Cliente("Daaniel", "2087537976", 55000.0);

	Cliente* c3 = new Cliente("Maria", "20832457976", 54060.0);
	Cliente* c4 = new Cliente("Elena", "29876127976", 65000.0);

	lista->agregarCliente(c1);
	lista->agregarCliente(c2);
	lista->agregarCliente(c3);
	lista->agregarCliente(c4);

	cout << "** Lista de clientes **" << endl << endl;
	cout << lista->mostrarCliente();

	cout << "*****Ordenamiento RADIX*******" << endl << endl;
	lista->OrdenamientoRadix();
	cout << lista->mostrarCliente();

	lista->cambiarSalario("2086757976", 70000);
	cout << "Cambio de salario " << endl << endl;
	cout << lista->mostrarCliente();

	cout << "*****Ordenamiento RADIX*******" << endl << endl;
	lista->OrdenamientoRadix();
	cout << lista->mostrarCliente();

	lista->eliminarCliente("2086757976");
	cout << "Lista despues de eliminar " << endl << endl;
	cout << lista->mostrarCliente();*/
}