#include "Interfaz.h"

Interfaz::Interfaz() : opc(-1) {

}

Interfaz::~Interfaz() {

}

void Interfaz::menuPrincipal() {
    cout << "-------------------------------\n";
    cout << "Bienvenido al Sistema Bancario.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Ingresar como Cliente.\n";
    cout << "2. Ingresar como Gerente.\n";
    cout << "3. Salir.\n";
    cout << "-------------------------------\n";
}

void Interfaz::menuCliente() {
    cout << "---------------------------------------------\n";
    cout << "Bienvenido al Sistema Bancario como Cliente.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Gestion de Clientes.\n";
    cout << "2. Operaciones Bancarias.\n";
    cout << "3. Volver al menu principal.\n";
    cout << "---------------------------------------------\n";
}

void Interfaz::menuGestionClientes() {
    cout << "-------------------------------\n";
    cout << "Gestion de Clientes.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Registrar Cliente.\n";
    cout << "2. Eliminar Cliente.\n";
    cout << "3. Volver al menu del cliente.\n";
    cout << "-------------------------------\n";
}

void Interfaz::menuOperacionesBancarias() {
    cout << "-------------------------------\n";
    cout << "Operaciones Bancarias.\n";
    cout << "|¿Que deseas hacer?|\n";
    cout << "1. Depositar dinero.\n";
    cout << "2. Retirar dinero.\n";
    cout << "3. Transferir dinero.\n";
    cout << "4. Volver al menu del cliente.\n";
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
    cout << "5. Volver al menu principal.\n";
    cout << "-------------------------------------------------------\n";
}

void Interfaz::iniciar() {

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

                            break;
                        case 2:
                            // Eliminar Cliente

                            break;
                        case 3:
                            // Volver al menu del cliente
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
                case 2:
                    // Operaciones Bancarias
                    do {
                        menuOperacionesBancarias();
                        opc = Interfaz::seleccionarOpcion();
                        system("cls");
                        switch (opc) {
                        case 1:
                            // Depositar dinero

                            break;
                        case 2:
                            // Retirar dinero

                            break;
                        case 3:
                            // Transferir dinero

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