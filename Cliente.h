#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    string direccion;
    static int ultimoId;

public:
    Cliente();
    Cliente(const string& nombre, const string& direccion);

    int getId() const;
    string getNombre() const;
    string getDireccion() const;
    void setNombre(const string& nombre);
    void setDireccion(const string& direccion);
    void setId(int id);
    static void setUltimoId(int id);
    static int getUltimoId();
};

#endif // CLIENTE_H