#ifndef CUENTA_H
#define CUENTA_H

#include <string>


using namespace std;

class Cuenta {
protected:
    int numero;
    double saldo;
    int idCliente;
    static int ultimoNumero;

public:
    Cuenta();
    Cuenta(int idCliente, double saldoInicial);

    int getNumero() const;
    double getSaldo() const;
    int getIdCliente() const;
    virtual bool consignar(double monto);
    virtual bool retirar(double monto);
    void setNumero(int numero);
    void setSaldo(double saldo);
    void setIdCliente(int idCliente);
    static void setUltimoNumero(int numero);
    static int getUltimoNumero();
    virtual string getTipo() const = 0;
};

#endif // CUENTA_H