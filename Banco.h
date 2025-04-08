#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <vector>
#include "Cliente.h"
#include "Cuenta.h"
#include "CuentaAhorro.h"
#include "CuentaCorriente.h"
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

class Banco {
private:
    string nombre;
    vector<Cliente> clientes;
    vector<Cuenta*> cuentas;

public:
    Banco(const string& nombre);

    string getNombre() const;
    void agregarCliente(const Cliente& cliente);
    void listarClientes() const;
    Cliente* buscarCliente(int id);
    int getTotalClientes() const;
    void agregarCuenta(Cuenta* cuenta);
    void listarCuentas() const;
    Cuenta* buscarCuenta(int numero);
    int getTotalCuentas() const;
    double getPromedioSaldoCuentas() const;
    int getNumCuentasAhorro() const;
    int getNumCuentasCorrientes() const;
    void aplicarInteresAhorros();
    bool consignarEnCuenta(int numeroCuenta, double monto);
    bool retirarDeCuenta(int numeroCuenta, double monto);
    bool guardarDatos(const string& nombreArchivo) const;
    bool cargarDatos(const string& nombreArchivo);
};

#endif // BANCO_H