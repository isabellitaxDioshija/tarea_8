#include <iostream>
#include <string>
#include "Banco.h"

using namespace std;

void mostrarMenuPrincipal();
void mostrarSubMenuClientes();
void mostrarSubMenuCuentas();
void mostrarSubMenuEstadisticas();
void mostrarSubMenuOperaciones();
void limpiar();
void manejarOpcionPrincipal(int opcion, Banco& banco);
void manejarSubMenuClientes(int opcion, Banco& banco);
void manejarSubMenuCuentas(int opcion, Banco& banco);
void manejarSubMenuEstadisticas(int opcion, Banco& banco);
void manejarSubMenuOperaciones(int opcion, Banco& banco);
void agregarCliente(Banco& banco);
void listarClientes(const Banco& banco);
void agregarCuenta(Banco& banco);
void listarCuentas(const Banco& banco);
void mostrarEstadisticas(const Banco& banco, int opcion);
void realizarOperacionFinanciera(Banco& banco, int opcion);

int main() {

    Banco banco("Banco Javeriano");
    cout << "Cargando datos del banco. " << endl;
    if (!banco.cargarDatos("BancoJaveriano.json")) {
        cout << "No se encontro archivo de datos." << endl;
    }

    int opcion = 0;

    do
        {
        mostrarMenuPrincipal();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        limpiar();

        manejarOpcionPrincipal(opcion, banco);

    }while (opcion != 5);
    cout << "Guardando datos." << endl;
    if (banco.guardarDatos("BancoJaveriano.json")) {
        cout << "Datos guardados correctamente." << endl;
    }else {
        cout << "Error al guardar los datos." << endl;
    }
    return 0;
}

void limpiar() {
    while (cin.get() != '\n') {
        continue;
    }
}

void mostrarMenuPrincipal() {
    cout << "\nSISTEMA BANCARIO JAVERIANO" << endl;
    cout << "1. Mantenimiento de Clientes" << endl;
    cout << "2. Mantenimiento de Cuentas" << endl;
    cout << "3. Estadisticas" <<endl;
    cout << "4. Operaciones Financieras" << endl;
    cout << "5. Salir" << endl;
}

void mostrarSubMenuClientes() {
    cout << "\nMANTENIMIENTO DE CLIENTES" << endl;
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Listar Clientes" <<endl;
    cout << "3. Volver al menu principal" << endl;
}

void mostrarSubMenuCuentas() {
    cout << "\nMANTENIMIENTO DE CUENTAS" << endl;
    cout << "1. Agregar Cuenta" << endl;
    cout << "2. Listar Cuentas" << endl;
    cout << "3. Volver al menu principal" << endl;

}

void mostrarSubMenuEstadisticas() {
    cout << "\nESTADÍSTICAS" << endl;
    cout << "1. Total de clientes" << endl;
    cout << "2. Total de cuentas" << endl;
    cout << "3. Promedio de saldos" << endl;
    cout << "4. Cuentas de ahorro" << endl;
    cout << "5. Cuentas corrientes" << endl;
    cout << "6. Volver al menu principal" << endl;
}

void mostrarSubMenuOperaciones() {
    cout << "\nOPERACIONES FINANCIERAS" << endl;
    cout << "1. Aplicar interes a cuentas de ahorro" << endl;
    cout << "2. Consignar" << endl;
    cout << "3. Retirar" << endl;
    cout << "4. Volver al menu principal" << endl;
}

void manejarOpcionPrincipal(int opcion, Banco& banco) {
    switch (opcion) {
        case 1: {
            int subOpcion;
            do {
                mostrarSubMenuClientes();
                cout << "Ingrese opcion: ";
                cin >> subOpcion;
                limpiar();
                manejarSubMenuClientes(subOpcion, banco);
            } while (subOpcion != 3);
            break;
        }
        case 2: {
            int subOpcion;
            do {
                mostrarSubMenuCuentas();
                cout << "Ingrese opcion: ";
                cin >> subOpcion;
                limpiar();
                manejarSubMenuCuentas(subOpcion, banco);
            } while (subOpcion != 3);
            break;
        }
        case 3: {
            int subOpcion;
            do {
                mostrarSubMenuEstadisticas();
                cout << "Ingrese opcion: ";
                cin >> subOpcion;
                limpiar();
                manejarSubMenuEstadisticas(subOpcion, banco);
            }while (subOpcion != 6);
            break;
        }
        case 4: {
            int subOpcion;
            do {
                mostrarSubMenuOperaciones();
                cout << "Ingrese opcion: ";
                cin >> subOpcion;
                limpiar();
                manejarSubMenuOperaciones(subOpcion, banco);
            } while (subOpcion != 4);
            break;
        }case 5:
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
    }
}

void manejarSubMenuClientes(int opcion, Banco& banco) {
    switch (opcion) {
        case 1:
            agregarCliente(banco);
            break;
        case 2:
            listarClientes(banco);
            break;
        case 3:
            cout << "Volviendo al menu principal" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
    }
}

void manejarSubMenuCuentas(int opcion, Banco& banco) {
    switch (opcion) {
        case 1:
            agregarCuenta(banco);
            break;
        case 2:
            listarCuentas(banco);
            break;
        case 3:
            cout << "Volviendo al menu principal" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
    }
}

void manejarSubMenuEstadisticas(int opcion, Banco& banco) {
    switch (opcion) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            mostrarEstadisticas(banco, opcion);
            break;
        case 6:
            cout << "Volviendo al menu principal " << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
    }
}

void manejarSubMenuOperaciones(int opcion, Banco& banco) {
    switch (opcion) {
        case 1:
        case 2:
        case 3:
            realizarOperacionFinanciera(banco, opcion);
            break;
        case 4:
            cout << "Volviendo al menu principal" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
    }
}

void agregarCliente(Banco& banco) {
    string nombre, direccion;

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombre);

    cout << "Ingrese la direccion del cliente: ";
    getline(cin, direccion);

    Cliente nuevoCliente(nombre, direccion);
    banco.agregarCliente(nuevoCliente);

    cout << "Cliente agregado con ID: " << nuevoCliente.getId() << endl;
}

void listarClientes(const Banco& banco) {
    banco.listarClientes();
}

void agregarCuenta(Banco& banco) {
    int idCliente;
    double saldoInicial;
    int tipoCuenta;

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;
    limpiar();

    Cliente* cliente = banco.buscarCliente(idCliente);
    if (!cliente) {
        cout << "Error. No existe un cliente con el ID: " << idCliente << endl;
        return;
    }

    cout << "Ingrese el saldo inicial: ";
    cin >> saldoInicial;
    limpiar();

    cout << "Tipo de cuenta (1: Ahorro, 2: Corriente): ";
    cin >> tipoCuenta;
    limpiar();

    Cuenta* nuevaCuenta = nullptr;

    if (tipoCuenta == 1) {
        double tasaInteres;
        cout << "Ingrese la tasa de interes: ";
        cin >> tasaInteres;
        limpiar();

        nuevaCuenta = new CuentaAhorro(idCliente, saldoInicial, tasaInteres);
    }else if (tipoCuenta == 2) {
        double limiteSobregiro;
        cout << "Ingrese el limite de sobregiro: ";
        cin >> limiteSobregiro;
        limpiar();
        nuevaCuenta = new CuentaCorriente(idCliente, saldoInicial, limiteSobregiro);

    }else {
        cout << "Tipo de cuenta invalido" << endl;
        return;
    }

    banco.agregarCuenta(nuevaCuenta);
    cout << "Cuenta agregada con numero: " << nuevaCuenta->getNumero() << endl;
}

void listarCuentas(const Banco& banco) {
    banco.listarCuentas();
}

void mostrarEstadisticas(const Banco& banco, int opcion) {
    switch (opcion) {
        case 1:
            cout << "Total de clientes: " << banco.getTotalClientes() << endl;
            break;
        case 2:
            cout << "Total de cuentas: " << banco.getTotalCuentas() << endl;
            break;
        case 3:
            cout << "Promedio del saldo de las cuentas: " << banco.getPromedioSaldoCuentas() << endl;
            break;
        case 4:
            cout << "Numero de cuentas de ahorro: " << banco.getNumCuentasAhorro() << endl;
            break;
        case 5:
            cout << "Numero de cuentas corrientes: " << banco.getNumCuentasCorrientes() << endl;
            break;
    }
}

void realizarOperacionFinanciera(Banco& banco, int opcion) {
    switch (opcion) {
        case 1:
            banco.aplicarInteresAhorros();
            cout << "Interes aplicado a todas las cuentas de ahorro." << endl;
            break;

        case 2: {
            int numeroCuenta;
            double monto;

            cout << "Ingrese el numero de cuenta: ";
            cin >> numeroCuenta;
            limpiar();

            cout << "Ingrese ela monto a consignar: ";
            cin >> monto;
            limpiar();

            if (banco.consignarEnCuenta(numeroCuenta, monto)) {
                cout << "Consignacion exitosa." << endl;
            }else
                {
                cout << "Error en la consignacion." << endl;
            }break;
        }

        case 3: {
            int numeroCuenta;
            double monto;

            cout << "Ingrese el numero de cuenta: ";
            cin >> numeroCuenta;
            limpiar();

            cout << "Ingrese el monto a retirar: ";
            cin >> monto;
            limpiar();

            if (banco.retirarDeCuenta(numeroCuenta, monto)) {
                cout << "Retiro exitoso." << endl;
            }else
                {
                cout << "Error en el retiro." << endl;
            }break;
        }
    }
}