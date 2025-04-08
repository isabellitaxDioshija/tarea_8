#ifndef CUENTA_CORRIENTE_H
#define CUENTA_CORRIENTE_H

#include "Cuenta.h"
#include<string>

using namespace std;

class CuentaCorriente : public Cuenta {
private:
    double limiteSobregiro;

public:
    CuentaCorriente();
    CuentaCorriente(int idCliente, double saldoInicial, double limiteSobregiro);

    double getLimiteSobregiro() const;
    void setLimiteSobregiro(double limiteSobregiro);
    bool retirar(double monto) override;
    string getTipo() const override;
};

#endif // CUENTA_CORRIENTE_H