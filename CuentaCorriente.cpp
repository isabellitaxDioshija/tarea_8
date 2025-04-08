#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente() : Cuenta(), limiteSobregiro(0.0) {
}

CuentaCorriente::CuentaCorriente(int idCliente, double saldoInicial, double limiteSobregiro) :
    Cuenta(idCliente, saldoInicial), limiteSobregiro(limiteSobregiro) {
}

double CuentaCorriente::getLimiteSobregiro() const {
    return limiteSobregiro;
}

void CuentaCorriente::setLimiteSobregiro(double limiteSobregiro) {
    this->limiteSobregiro = limiteSobregiro;
}

bool CuentaCorriente::retirar(double monto) {
    if (monto > 0) {
        if (monto <= (saldo + limiteSobregiro)) {
            saldo -= monto;
            return true;
        }
    }return false;
}

string CuentaCorriente::getTipo() const {
    return "Corriente";
}