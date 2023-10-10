#include "Interfaz.h"

Interfaz::Interfaz() : opc(-1), clientes(new listaCliente()) {

}

Interfaz::~Interfaz() {

}

void Interfaz::menuPrincipal() {
    cout << "-------------------------------\n";
    cout << "Bienvenido al Sistema Bancario.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Ingresar como Cliente.\n";
    cout << "2. Ingresar como Gerente.\n";
    cout << "3. Salir.\n"; // listo
    cout << "-------------------------------\n";
}

void Interfaz::menuCliente() {
    cout << "---------------------------------------------\n";
    cout << "Bienvenido al Sistema Bancario como Cliente.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Gestion de Clientes.\n";
    cout << "2. Operaciones Bancarias.\n";
    cout << "3. Volver al menu principal.\n"; // listo
    cout << "---------------------------------------------\n";
}

void Interfaz::menuGestionClientes() {
    cout << "-------------------------------\n";
    cout << "Gestion de Clientes.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Registrar Cliente.\n"; // listo
    cout << "2. Eliminar Cliente.\n"; // listo
    cout << "3. Mostrar Clientes.\n"; // listo
    cout << "4. Volver al menu del cliente.\n"; // listo
    cout << "-------------------------------\n";
}

void Interfaz::menuOperacionesBancarias() {
    cout << "-------------------------------\n";
    cout << "Operaciones Bancarias.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Depositar saldo.\n"; // listo
    cout << "2. Retirar saldo.\n"; // listo
    cout << "3. Transferir saldo.\n";
    cout << "4. Volver al menu del cliente.\n"; // listo
    cout << "-------------------------------\n";
}

void Interfaz::menuGerente() {
    cout << "-------------------------------------------------------\n";
    cout << "Bienvenido al Sistema Bancario como Gerente.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Aprobacion y Denegacion de solicitudes de tarjetas.\n";
    cout << "2. Registro de solicitudes de tarjetas.\n";
    cout << "3. Historial de Transacciones.\n";
    cout << "4. Aceptacion y cancelacion de tranferencias.\n";
    cout << "5. Volver al menu principal.\n"; // listo
    cout << "-------------------------------------------------------\n";
}

void Interfaz::iniciar() {

    Cliente* cliente;
    GeneradorCuentas* generador = new GeneradorCuentas();
    string nombre, cedula;
    double saldo = 0.0;
    int cuenta = 0, cuenta2 = 0;

    do {
        menuPrincipal();
        opc = Interfaz::seleccionarOpcion();
        system("cls");
        switch (opc) {
        case 1:
            //Ingresar como Cliente
            do {
                menuCliente();
                opc = Interfaz::seleccionarOpcion();
                system("cls");
                switch (opc) {
                case 1:
                    // Gestion de Clientes
                    do {
                        menuGestionClientes();
                        opc = Interfaz::seleccionarOpcion();
                        system("cls");
                        switch (opc) {
                        case 1:
                            // Registrar Cliente
                            cout << "-------------------------------------------\n";
                            cout << "Digite el nombre del nuevo cliente: ";
                            getline(cin, nombre);
                            cout << "Digite la cedula del nuevo cliente: ";
                            cin >> cedula;
                            while (clientes->encontrarCliente(cedula)) {
                                cout << "La cedula ya existe, por favor digite otra: ";
                                cin >> cedula;
                            }
                            cout << "Digite el saldo del nuevo cliente: ";
                            saldo = Utiles::validarDecimal();
                            cout << "-------------------------------------------\n";
                            cliente = new Cliente(nombre, cedula, saldo);
                            cliente->setNumCuenta(generador);
                            clientes->agregarCliente(cliente);
                            cout << "\n------------------------------\n";
                            cout << "Cliente agregado exitosamente.\n";
                            cout << "------------------------------\n";
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            // Eliminar Cliente
                            cout << "----------------------\n";
                            cout << "Cedulas disponibles:\n";
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
                        case 3:
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
                        case 4:
                            // Volver al menu del cliente
                            break;
                        default:
                            cout << Utiles::opcionInvalida();
                            system("pause");
                            system("cls");
                            break;
                        }
                    } while (opc != 4);
                    opc = 0;
                    break;
                case 2:
                    // Operaciones Bancarias
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
                            // Retirar saldo
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
                            else {
                                cout << "\n----------------------------\n";
                                cout << "La cuenta bancaria no fue encontrada.\n";
                                cout << "----------------------------\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            // Transferir dinero
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
                                cout << "La cuenta bancaria no fue encontrada.\n";
                                cout << "----------------------------\n";
                            }
                            break;
                        case 4:
                            // Volver al menu del cliente
                            break;
                        default:
                            cout << Utiles::opcionInvalida();
                            system("pause");
                            system("cls");
                            break;
                        }
                    } while (opc != 4);
                    opc = 0;
                    break;
                case 3:
                    // Volver al menu principal
                    break;
                default:
                    cout << Utiles::opcionInvalida();
                    system("pause");
                    system("cls");
                    break;
                }
            } while (opc != 3);
            opc = 0;
            break;
            // Ingresar como Gerente
        case 2:
            do {
                menuGerente();
                opc = Interfaz::seleccionarOpcion();
                system("cls");
                switch (opc) {
                case 1:
                    // Aprobacion y Denegacion de solicitudes de tarjetas

                    break;
                case 2:
                    // Registro de solicitudes de tarjetas

                    break;
                case 3:
                    // Historial de Transacciones

                    break;
                case 4:
                    // Aceptación y cancelación de tranferencias

                    break;
                case 5:
                    // Volver al menu principal
                    break;
                default:
                    cout << Utiles::opcionInvalida();
                    system("pause");
                    system("cls");
                    break;
                }
            } while (opc != 5);
            opc = 0;
            break;
        case 3:
            // Salir
            break;
        default:
            cout << Utiles::opcionInvalida();
            system("pause");
            system("cls");
            break;
        }

    } while (opc != 3);
    cout << "Gracias por visitar el Sistema Bancario.\n";
}

//Selecciona una opcion y retorna un entero
int Interfaz::seleccionarOpcion() {
    int opcion = 0;
    cout << "Digite una opcion: ";
    opcion = Utiles::validarEntero();
    return opcion;
}