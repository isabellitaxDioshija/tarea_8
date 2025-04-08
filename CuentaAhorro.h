#ifndef CUENTA_AHORRO_H
#define CUENTA_AHORRO_H

#include "Cuenta.h"
#include<string>

using namespace std;

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;
public:
    CuentaAhorro();
    CuentaAhorro(int idCliente, double saldoInicial, double tasaInteres);

    double getTasaInteres() const;
    void setTasaInteres(double tasaInteres);
    void aplicarInteres();
    string getTipo() const override;
};

#endif // CUENTA_AHORRO_H