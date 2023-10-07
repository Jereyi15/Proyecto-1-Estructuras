#include <string>

#include "Utiles.h"
#include "listaCliente.h"

class Interfaz
{
public:
	Interfaz();
	virtual ~Interfaz();
	virtual void menuPrincipal();
	virtual void menuCliente();
	virtual void menuGestionClientes();
	virtual void menuOperacionesBancarias();
	virtual void menuGerente();

	virtual void iniciar();
	virtual int seleccionarOpcion();

private:
	int opc;
	listaCliente* clientes;
};