#include "Cuenta.h"

int Cuenta::ultimoNumero = 99;

Cuenta::Cuenta() : numero(0), saldo(0), idCliente(0) {
}

Cuenta::Cuenta(int idCliente, double saldoInicial) :
    idCliente(idCliente), saldo(saldoInicial) {
    numero = ++ultimoNumero;
}

int Cuenta::getNumero() const {
    return numero;
}

double Cuenta::getSaldo() const {
    return saldo;
}

int Cuenta::getIdCliente() const {
    return idCliente;
}

bool Cuenta::consignar(double monto) {
    if (monto > 0) {
        saldo += monto;
        return true;
    }
    return false;
}

bool Cuenta::retirar(double monto) {
    if (monto > 0 && monto <= saldo) {
        saldo -= monto;
        return true;
    }
    return false;
}

void Cuenta::setNumero(int numero) {
    this->numero = numero;
}

void Cuenta::setSaldo(double saldo) {
    this->saldo = saldo;
}

void Cuenta::setIdCliente(int idCliente) {
    this->idCliente = idCliente;
}

void Cuenta::setUltimoNumero(int numero) {
    ultimoNumero = numero;
}

int Cuenta::getUltimoNumero() {
    return ultimoNumero;
}