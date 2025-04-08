#include "Banco.h"
#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

Banco::Banco(const string& nombre) : nombre(nombre) {}

string Banco::getNombre() const { return nombre; }

void Banco::agregarCliente(const Cliente& cliente) {
    clientes.push_back(cliente);
}

void Banco::agregarCuenta(Cuenta* cuenta) {
    cuentas.push_back(cuenta);
}

Cliente* Banco::buscarCliente(int id) {
    for (unsigned i = 0; i < clientes.size(); i++) {
        if (clientes[i].getId() == id) {
            return &clientes[i];
        }
    }
    return nullptr;
}

Cuenta* Banco::buscarCuenta(int numero) {
    for (unsigned i = 0; i < cuentas.size(); i++) {
        if (cuentas[i]->getNumero() == numero) {
            return cuentas[i];
        }
    }
    return nullptr;
}

void Banco::listarClientes() const {
    cout << "CLIENTES (" << clientes.size() << ")\n";
    for (unsigned i = 0; i < clientes.size(); i++) {
        cout << " ID: " << clientes[i].getId()
             << " Nombre: " << clientes[i].getNombre()
             << " Dirección: " << clientes[i].getDireccion() << "\n";
    }
}

void Banco::listarCuentas() const {
    cout << "CUENTAS (" << cuentas.size() << ")\n";
    for (unsigned i = 0; i < cuentas.size(); i++) {
        cout << "Nº: " << cuentas[i]->getNumero()
             << " Tipo: " << cuentas[i]->getTipo()
             << " Cliente ID: " << cuentas[i]->getIdCliente()
             << " Saldo: " << cuentas[i]->getSaldo();

        if (cuentas[i]->getTipo() == "Ahorro") {
            CuentaAhorro* aho = dynamic_cast<CuentaAhorro*>(cuentas[i]);
            cout << " Interés: " << aho->getTasaInteres() << "%";
        } else if (cuentas[i]->getTipo() == "Corriente") {
            CuentaCorriente* cc = dynamic_cast<CuentaCorriente*>(cuentas[i]);
            cout << " Sobregiro: " << cc->getLimiteSobregiro();
        }
        cout << endl;
    }
}

int Banco::getTotalClientes() const { return clientes.size(); }
int Banco::getTotalCuentas() const { return cuentas.size(); }

double Banco::getPromedioSaldoCuentas() const {
    if (cuentas.size() == 0) return 0.0;

    double total = 0;
    for (unsigned i = 0; i < cuentas.size(); i++) {
        total += cuentas[i]->getSaldo();
    }
    return total / cuentas.size();
}

int Banco::getNumCuentasAhorro() const {
    int cont = 0;
    for (unsigned i = 0; i < cuentas.size(); i++) {
        if (cuentas[i]->getTipo() == "Ahorro") cont++;
    }
    return cont;
}

int Banco::getNumCuentasCorrientes() const {
    int cont = 0;
    for (unsigned i = 0; i < cuentas.size(); i++) {
        if (cuentas[i]->getTipo() == "Corriente") cont++;
    }
    return cont;
}

void Banco::aplicarInteresAhorros() {
    for (unsigned i = 0; i < cuentas.size(); i++) {
        if (cuentas[i]->getTipo() == "Ahorro") {
            CuentaAhorro* aho = dynamic_cast<CuentaAhorro*>(cuentas[i]);
            aho->aplicarInteres();
        }
    }
}

bool Banco::consignarEnCuenta(int numeroCuenta, double monto) {
    Cuenta* cuenta = buscarCuenta(numeroCuenta);
    if (cuenta != nullptr) {
        return cuenta->consignar(monto);
    }
    return false;
}

bool Banco::retirarDeCuenta(int numeroCuenta, double monto) {
    Cuenta* cuenta = buscarCuenta(numeroCuenta);
    if (cuenta != nullptr) {
        return cuenta->retirar(monto);
    }
    return false;
}

bool Banco::guardarDatos(const string& nombreArchivo) const {
    json j;
    j["nombre"] = nombre;

    // Guardar últimos IDs
    j["ultimoIdCliente"] = Cliente::getUltimoId();
    j["ultimoNumeroCuenta"] = Cuenta::getUltimoNumero();

    // Guardar clientes
    json jClientes = json::array();
    for (const auto& cliente : clientes) {
        json jCliente;
        jCliente["id"] = cliente.getId();
        jCliente["nombre"] = cliente.getNombre();
        jCliente["direccion"] = cliente.getDireccion();
        jClientes.push_back(jCliente);
    }
    j["clientes"] = jClientes;

    // Guardar cuentas
    json jCuentas = json::array();
    for (const auto& cuenta : cuentas) {
        json jCuenta;
        jCuenta["numero"] = cuenta->getNumero();
        jCuenta["idCliente"] = cuenta->getIdCliente();
        jCuenta["saldo"] = cuenta->getSaldo();
        jCuenta["tipo"] = cuenta->getTipo();

        if (cuenta->getTipo() == "Ahorro") {
            const CuentaAhorro* cuentaAhorro = dynamic_cast<const CuentaAhorro*>(cuenta);
            jCuenta["tasaInteres"] = cuentaAhorro->getTasaInteres();
        } else if (cuenta->getTipo() == "Corriente") {
            const CuentaCorriente* cuentaCorriente = dynamic_cast<const CuentaCorriente*>(cuenta);
            jCuenta["limiteSobregiro"] = cuentaCorriente->getLimiteSobregiro();
        }

        jCuentas.push_back(jCuenta);
    }
    j["cuentas"] = jCuentas;

    // Guardar en archivo
    ofstream archivo(nombreArchivo);
    if (!archivo) return false;

    archivo << j.dump(4); // Con sangría de 4 espacios para mejor legibilidad
    archivo.close();
    return true;
}

bool Banco::cargarDatos(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) return false;

    // Limpiar datos actuales
    for (auto cuenta : cuentas) {
        delete cuenta;
    }
    cuentas.clear();
    clientes.clear();

    // Cargar JSON
    json j;
    try {
        archivo >> j;
    } catch (...) {
        archivo.close();
        return false;
    }
    archivo.close();

    // Cargar nombre del banco
    if (j.contains("nombre")) {
        nombre = j["nombre"].get<string>();
    }

    // Cargar últimos IDs
    if (j.contains("ultimoIdCliente")) {
        Cliente::setUltimoId(j["ultimoIdCliente"].get<int>());
    }
    if (j.contains("ultimoNumeroCuenta")) {
        Cuenta::setUltimoNumero(j["ultimoNumeroCuenta"].get<int>());
    }

    // Cargar clientes
    if (j.contains("clientes") && j["clientes"].is_array()) {
        for (const auto& jCliente : j["clientes"]) {
            Cliente cliente;
            cliente.setId(jCliente["id"].get<int>());
            cliente.setNombre(jCliente["nombre"].get<string>());
            cliente.setDireccion(jCliente["direccion"].get<string>());
            clientes.push_back(cliente);
        }
    }

    // Cargar cuentas
    if (j.contains("cuentas") && j["cuentas"].is_array()) {
        for (const auto& jCuenta : j["cuentas"]) {
            Cuenta* cuenta = nullptr;
            int numeroCuenta = jCuenta["numero"].get<int>();
            int idCliente = jCuenta["idCliente"].get<int>();
            double saldo = jCuenta["saldo"].get<double>();
            string tipo = jCuenta["tipo"].get<string>();

            if (tipo == "Ahorro") {
                double tasaInteres = jCuenta["tasaInteres"].get<double>();
                CuentaAhorro* cuentaAhorro = new CuentaAhorro(idCliente, saldo, tasaInteres);
                cuentaAhorro->setNumero(numeroCuenta);
                cuenta = cuentaAhorro;
            } else if (tipo == "Corriente") {
                double limiteSobregiro = jCuenta["limiteSobregiro"].get<double>();
                CuentaCorriente* cuentaCorriente = new CuentaCorriente(idCliente, saldo, limiteSobregiro);
                cuentaCorriente->setNumero(numeroCuenta);
                cuenta = cuentaCorriente;
            }

            if (cuenta != nullptr) {
                cuentas.push_back(cuenta);
            }
        }
    }

    return true;
}