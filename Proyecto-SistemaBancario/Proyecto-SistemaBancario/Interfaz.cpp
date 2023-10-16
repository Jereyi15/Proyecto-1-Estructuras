#include "Interfaz.h"

Interfaz::Interfaz() : opc(-1), clientes(new listaCliente()), gerente(Gerente("jefeirpaga")) { // se crea un solo gerente que la clave va a ser el acronimo de los desarrolladores(si quieren lo pueden cambiar)

}

Interfaz::~Interfaz() {

}

void Interfaz::menuPrincipal() {
    system("cls");
    cout << "-------------------------------\n";
    cout << "Bienvenido al Sistema Bancario.\n";
    cout << "| Que deseas hacer?|\n";
    cout << "1. Ingresar como Cliente.\n";
    cout << "2. Ingresar como Gerente.\n";
    cout << "3. Registrar cliente nuevo.\n";
    cout << "4. Salir.\n"; // listo
    cout << "-------------------------------\n";
}

void Interfaz::menuCliente() {
    cout << "---------------------------------------------\n";
    cout << "Bienvenido al Sistema Bancario como Cliente.\n";
    cout << "| Que deseas hacer?|\n";
    cout << "1. Operaciones Bancarias.\n";
    cout << "2. Registrar solicitud de tarjeta de credito.\n";
    cout << "3. Cerrar sesion.\n"; // listo
    cout << "---------------------------------------------\n";
}

void Interfaz::menuGestionClientes() {
    cout << "-------------------------------\n";
    cout << "Gestion de Clientes.\n";
    cout << "| Que deseas hacer?|\n";
    cout << "1. Eliminar Cliente.\n"; // listo
    cout << "2. Mostrar Clientes.\n"; // listo
    cout << "4. Volver al menu del Gerente.\n"; // listo
    cout << "-------------------------------\n";
}

void Interfaz::menuOperacionesBancarias() {
    cout << "-------------------------------\n";
    cout << "Operaciones Bancarias.\n";
    cout << "| Que deseas hacer?|\n";
    cout << "1. Depositar saldo.\n"; // listo
    cout << "2. Retirar saldo.\n"; // listo
    cout << "3. Transferir saldo.\n";
    cout << "4. Volver al menu del cliente.\n"; // listo
    cout << "-------------------------------\n";
}

void Interfaz::menuGerente() {
    cout << "-------------------------------------------------------\n";
    cout << "Bienvenido al Sistema Bancario como Gerente.\n";
    cout << "| Que deseas hacer?|\n";
    cout << "1. Gestion de Clientes.\n";
    cout << "2. Aprobacion y Denegacion de solicitudes de tarjetas.\n";
    cout << "3. Historial de Transacciones Bancarias.\n";
    cout << "4. Deshacer Transaccion Bancaria\n";
    cout << "5. Cerrar sesion.\n"; // listo
    cout << "-------------------------------------------------------\n";
}

void Interfaz::menuDeshacerTransaccion() { // nuevooo
    cout << "-------------------------------------------------------\n";
    cout << "| Que tipo de transacción bancaria desea deshacer?|\n";
    cout << "1. Retiro.\n";
    cout << "2. Deposito.\n";
    cout << "3. Transferencia entre cuentas.\n";
    cout << "4. Volver al menu del Gerente.\n";
    cout << "-------------------------------------------------------\n";
}

void Interfaz::iniciar() {

    Cliente* cliente;
    string nombre, cedula, contrasenna;
    double saldo = 0.0;
    int cuenta = 0, cuenta2 = 0;

    do {
        menuPrincipal();
        opc = Interfaz::seleccionarOpcion();
        system("cls");
        switch (opc) {
        case 1:
            //Iniciar sesion como cliente
            if (clientes->cantClientes() == 0) {
                cout << "\n------------------------------------------------------------------------------------\n";
                cout << "     Para poder iniciar sesión asegurate haber registrado un perfil de cliente.\n";
                cout << "------------------------------------------------------------------------------------\n";
                system("pause");
                system("cls");
                break;
            }
            else if (iniciarSesionComoCliente() == true) {
                system("cls");
                cout << "-------------Bienvenido----------------" << endl;
                do {
                    menuCliente();
                    opc = Interfaz::seleccionarOpcion();
                    system("cls");
                    switch (opc) {
                    case 1:
                        //Operaciones Bancarias

                        do {
                            menuOperacionesBancarias();
                            opc = Interfaz::seleccionarOpcion();
                            system("cls");
                            switch (opc) {
                            case 1:
                                // Depositar saldo
                                cout << "----------------------\n";
                                cout << "Cuentas bancarias disponibles:\n";
                                cout << clientes->mostrarCuentasBancarias();
                                cout << "----------------------\n\n";
                                cout << "Digite el numero de cuenta del cliente a depositar saldo: ";
                                cin >> cuenta;
                                if (clientes->encontrarClienteNum(cuenta)) {
                                    cout << "Digite el saldo a depositar: ";
                                    saldo = Utiles::validarDecimal();
                                    if (saldo > 0) {
                                        clientes->depositarSaldo(cuenta, saldo);
                                        cout << "\n-----------------\n";
                                        cout << "Deposito exitoso.\n";
                                        cout << "-----------------\n";
                                    }
                                    else {
                                        cout << "\n----------------------------\n";
                                        cout << "El saldo debe ser mayor a 0.\n";
                                        cout << "----------------------------\n";
                                    }
                                }
                                else {
                                    cout << "\n----------------------------\n";
                                    cout << "La cuenta bancaria no fue encontrada.\n";
                                    cout << "----------------------------\n";
                                }
                                system("pause");
                                system("cls");
                                break;
                            case 2:
                                //Retiro de dinero
                                cout << "----------------------\n";
                                cout << "Cuentas bancarias disponibles:\n";
                                cout << clientes->mostrarCuentasBancarias();
                                cout << "----------------------\n\n";
                                cout << "Digite la cuenta bancaria del cliente a retirar saldo: ";
                                cin >> cuenta;
                                if (clientes->encontrarClienteNum(cuenta)) {
                                    cout << "Digite el saldo a retirar: ";
                                    saldo = Utiles::validarDecimal();
                                    if (saldo > 0 && clientes->verificarSaldoRetirar(cuenta, saldo)) {
                                        clientes->retirarSaldo(cuenta, saldo);
                                        cout << "\n---------------\n";
                                        cout << "Retiro exitoso.\n";
                                        cout << "---------------\n";
                                    }
                                    else {
                                        cout << "\n----------------------------------------------------------------------------------\n";
                                        cout << "El saldo debe ser mayor a 0 y menor a la cantidad de saldo que posee en la cuenta.\n";
                                        cout << "----------------------------------------------------------------------------------\n";
                                    }
                                }
                                system("pause");
                                system("cls");
                                break;
                            case 3:
                                //Transferencias entre cuentas
                                if (clientes->cantClientes() >= 2) {
                                    cout << "----------------------\n";
                                    cout << "Cuentas bancarias disponibles:\n";
                                    cout << clientes->mostrarCuentasBancarias();
                                    cout << "----------------------\n\n";
                                    cout << "Digite la cuenta bancaria del cliente que va a transferir saldo entre cuentas: ";
                                    cin >> cuenta;
                                    if (clientes->encontrarClienteNum(cuenta)) {
                                        system("pause");
                                        system("cls");

                                        cout << "----------------------\n";
                                        cout << "Cuentas bancarias disponibles:\n";
                                        cout << clientes->mostrarCuentasBancarias();
                                        cout << "----------------------\n\n";
                                        cout << "Digite la cuenta bancaria a la que desea transferir el dinero: ";
                                        cin >> cuenta2;
                                        if (cuenta != cuenta2) {
                                            if (clientes->encontrarClienteNum(cuenta2)) {
                                                cout << "Digite el monto que desea transferir: ";
                                                cin >> saldo;

                                                // Obtener el primer cliente
                                                Cliente* clienteOrigen = clientes->encontrarClienteObj(cuenta);
                                                // Obtener el segundo cliente
                                                Cliente* clienteDestino = clientes->encontrarClienteObj(cuenta2);

                                                //Transferencia
                                                if (clientes->transferenciaBancaria(cuenta, clienteDestino, saldo)) {
                                                    cout << "\n-----------------\n";
                                                    cout << "Transferencia exitosa.\n";
                                                    cout << "-----------------\n";
                                                }
                                                else {
                                                    cout << "\n----------------------------\n";
                                                    cout << "No hay suficientes fondos o la cuenta origen no fue encontrada.\n";
                                                    cout << "----------------------------\n";
                                                }
                                            }
                                            else {
                                                cout << "\n----------------------------\n";
                                                cout << "La cuenta bancaria a la que desea transferir el dinero no fue encontrada.\n";
                                                cout << "----------------------------\n";
                                            }
                                        }
                                        else {
                                            cout << "\n----------------------------\n";
                                            cout << "Lo sentimos, la tranferencia no se ha podido realizar. La cuenta de origen y de destino deben ser distintas.\n";
                                            cout << "----------------------------\n";
                                        }
                                    }
                                    else {
                                        cout << "\n----------------------------\n";
                                        cout << "La cuenta bancaria no fue encontrada.\n";
                                        cout << "----------------------------\n";
                                    }
                                }
                                else {
                                    cout << "\n----------------------------------------------------------------------------------------------------------------\n";
                                    cout << "  Para poder realizar una tranferencia entre cuentas, deben existir al menos dos cuentas asociadas clientes.\n";
                                    cout << "----------------------------------------------------------------------------------------------------------------\n";
                                }
                                system("pause");
                                system("cls");
                                break;
                            case 4:
                                //Salir
                                system("pause");
                                system("cls");
                                break;
                            default:
                                cout << Utiles::opcionInvalida();
                                system("pause");
                                system("cls");
                                break;
                            }

                        } while (opc != 4);
                        break;
                    case 2:
                        //Registro de solicitudes de tarjetas de credito //Hace falta
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        //Salir 
                        system("pause");
                        system("cls");
                        break;
                    default:
                        cout << Utiles::opcionInvalida();
                        system("pause");
                        system("cls");
                        break;
                    }

                } while (opc != 3);

                //Aca se termina la sesion del cliente
            }
            else {
                cout << "\n----------------------------\n";
                cout << "Inicio de sesion fallido.\n";
                cout << "----------------------------\n";
                system("pause");
                system("cls");
            }
            break;
        case 2:
            //Inicio de sesion como Gerente
            if (iniciarSesionComoGerente() == true) {
                do {
                    system("cls");
                    menuGerente();
                    opc = Interfaz::seleccionarOpcion();
                    system("cls");

                    switch (opc) {
                    case 1:
                        //Gestion de Clientes
                        do {
                            menuGestionClientes();
                            opc = Interfaz::seleccionarOpcion();
                            system("cls");
                            switch (opc) {
                            case 1:
                                // Eliminar Cliente
                                cout << "----------------------\n";
                                cout << "Cedulas de clientes afiliados:\n";
                                cout << clientes->mostrarCedulas();
                                cout << "----------------------\n\n";
                                cout << "Digite la cedula del cliente a eliminar: ";
                                cin >> cedula;
                                if (clientes->encontrarCliente(cedula)) {
                                    clientes->eliminarCliente(cedula);
                                    cout << "\n----------------------------\n";
                                    cout << "Cliente eliminado con exito.\n";
                                    cout << "----------------------------\n";
                                }
                                else {
                                    cout << "\n----------------------------\n";
                                    cout << "La cedula no fue encontrada.\n";
                                    cout << "----------------------------\n";
                                }
                                system("pause");
                                system("cls");
                                break;
                            case 2:
                                // Mostrar Clientes
                                if (clientes->hayClientes()) {
                                    clientes->OrdenamientoRadix();
                                    cout << clientes->mostrarCliente();
                                }
                                else {
                                    cout << "\n---------------------------------------\n";
                                    cout << "No hay clientes en el sistema bancario.\n";
                                    cout << "---------------------------------------\n";
                                }
                                system("pause");
                                system("cls");
                                break;
                            case 3:
                                //Salir 
                                system("pause");
                                system("cls");
                                break;
                            default:
                                cout << Utiles::opcionInvalida();
                                system("pause");
                                system("cls");
                                break;
                            }
                        } while (opc = !3);
                        break;
                    case 2:
                        //Aprobacion y Denegacion de solicitudes de tarjetas de credito //Hace falta
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        // Historial de Transacciones
                        cout << clientes->mostrarHistorialTransacciones();
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        //Deshacer transacciones bancarias //Hace falta
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        //Cerrar Sesion
                        system("pause");
                        system("cls");
                        break;
                    default:
                        cout << Utiles::opcionInvalida();
                        system("pause");
                        system("cls");
                        break;
                    }
                } while (opc != 5);
            }
            else {
                cout << "\n------------------------------------------\n";
                cout << "Inicio de sesion fallido, intentelo de nuevo.\n";
                cout << "------------------------------------------\n";
            }
            break;
        case 3:
            //Crear cuentas de usuario cliente
            crearCuentaCliente();
            break;
        }
    } while (opc != 4);
    cout << "\n------------------------------------------\n";
    cout << " Gracias por visitar el Sistema Bancario.\n";
    cout << "------------------------------------------\n";
    system("pause");
    system("cls");
}

//Selecciona una opcion y retorna un entero
int Interfaz::seleccionarOpcion() {
    int opcion = 0;
    cout << "Digite una opcion: ";
    opcion = Utiles::validarEntero();
    return opcion;
}

bool Interfaz::iniciarSesionComoGerente()
{
    string _contrasenna;
    system("cls");
    cout << "-------------------------------\n";
    cout << "Ingresar como Gerente.\n";
    cout << "|Digite la contrasenna|\n";
    cin >> _contrasenna;
    if (_contrasenna == gerente.getContrasena()) {
        cout << "\nContrasenna correcta.\n\n";
        cout << "-------------------------------\n";
        system("pause");
        return true;
    }
    else
        cout << "\nContrasenna invalida, intentelo de nuevo.\n\n";
    cout << "-------------------------------\n";
    system("pause");
    return false;
}

bool Interfaz::iniciarSesionComoCliente()
{
    menuPrincipal();
    string _contrasenna, _cedula;
    system("cls");
    cout << "-------------------------------\n";
    cout << "Ingresar como Cliente.\n";
    cout << "|Digite el numero de cedula|\n";
    cin >> _cedula;
    cout << "|Digite la contrasenna|\n";
    cin >> _contrasenna;
    if (clientes->encontrarClienteObj2(_cedula) != nullptr && _contrasenna == clientes->recuperarCliente(_cedula)->getContrasena()) {
        cout << "\nContrasenna correcta.\n\n";
        cout << "-------------------------------\n";
        system("pause");
        return true;
    }
    else
        cout << "\nContrasenna o usuario no valido, intentelo de nuevo.\n\n";
    cout << "-------------------------------\n";
    system("pause");
    return false;
}

bool Interfaz::crearCuentaCliente()
{
    Cliente* cliente;
    GeneradorCuentas* generador = new GeneradorCuentas();
    string nombre, cedula, contrasenna;
    double saldo = 0.0;
    int cuenta = 0;
    bool flag = false;

    // Registrar Cliente
    cout << "-------------------------------------------\n";
    cout << "Digite el nombre del nuevo cliente: ";
    cin >> nombre;
    cout << "Digite la cedula del nuevo cliente: ";
    cin >> cedula;
    while (clientes->encontrarCliente(cedula)) {
        cout << "La cedula ya existe, por favor digite otra: ";
        cin >> cedula;
    }
    cout << "Digite la contrasenna de la cuenta del nuevo cliente: ";
    cin >> contrasenna;
    do {
        cout << "Ingrese el saldo del nuevo cliente: ";
        saldo = Utiles::validarDecimal();
        if (saldo > 0) {
            cout << "-------------------------------------------\n";
            cliente = new Cliente(nombre, cedula, contrasenna, saldo);
            cliente->setNumCuenta(generador);
            clientes->agregarCliente(cliente);
            cout << "\n------------------------------\n";
            cout << "Cliente agregado exitosamente.\n";
            cout << "------------------------------\n";
            system("pause");
            system("cls");
            flag = true;
        }
        else {
            cout << "\n------------------------------\n";
            cout << "El saldo ingreso debe ser mayor a 0.\n";
            cout << "------------------------------\n";
            flag = false;
        }
    } while (flag == false);

    return true;
}