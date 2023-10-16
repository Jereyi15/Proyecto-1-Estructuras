#include <string>
#include "Gerente.h"
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

	virtual bool iniciarSesionComoGerente(); // solo tiene iniciar secion para que no se puedan crear cuentas de gerentes

	virtual void menuDeshacerTransaccion();
	virtual bool iniciarSesionComoCliente();
	virtual bool crearCuentaCliente();

private:
	int opc;
	listaCliente* clientes;
	Gerente gerente;//new
};