#include "Cliente.h"

int Cliente::ultimoId = 0;

Cliente::Cliente() : id(0), nombre(""), direccion("") {
}

Cliente::Cliente(const string& nombre, const string& direccion) :
    nombre(nombre), direccion(direccion) {
    id = ++ultimoId;
}

int Cliente::getId() const {
    return id;
}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Cliente::setDireccion(const string& direccion) {
    this->direccion = direccion;
}

void Cliente::setId(int id) {
    this->id = id;
}

void Cliente::setUltimoId(int id) {
    ultimoId = id;
}

int Cliente::getUltimoId() {
    return ultimoId;
}