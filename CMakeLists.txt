cmake_minimum_required(VERSION 3.30)
project(tarea_8BIEN)

set(CMAKE_CXX_STANDARD 20)

add_executable(tarea_8BIEN main.cpp
        Banco.cpp
        Banco.h
        Cliente.cpp
        Cliente.h
        CuentaCorriente.cpp
        CuentaCorriente.h
        CuentaAhorro.cpp
        CuentaAhorro.h
        Cuenta.cpp
        Cuenta.h)
