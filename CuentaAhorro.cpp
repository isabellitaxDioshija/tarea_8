#include "CuentaAhorro.h"

CuentaAhorro::CuentaAhorro() : Cuenta(), tasaInteres(0.0) {
}

CuentaAhorro::CuentaAhorro(int idCliente, double saldoInicial, double tasaInteres) :
    Cuenta(idCliente, saldoInicial), tasaInteres(tasaInteres) {
}

double CuentaAhorro::getTasaInteres() const {
    return tasaInteres;
}

void CuentaAhorro::setTasaInteres(double tasaInteres) {
    this->tasaInteres = tasaInteres;
}

void CuentaAhorro::aplicarInteres() {
    double interes = saldo * (tasaInteres / 100.0);
    saldo += interes;
}

string CuentaAhorro::getTipo() const {
    return "Ahorro";
}