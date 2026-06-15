#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#include "Mostrable.cpp"
#include "UI.cpp"

using namespace std;

enum Modo
{
    Renta,
    Venta
};

class Transaccion : public Mostrable
{
private:
    int numFolio;
    int clienteID;
    int empleadoID;
    int productoID;
    Modo modoTransaccion;

public:
    Transaccion();
    Transaccion(int numFolio, int clienteID, int empleadoID, int productoID, Modo modoTransaccion);
    ~Transaccion();

    int getNumFolio() const;
    void setNumFolio(int folio);
    int getClienteID() const;
    void setClienteID(int id);
    int getEmpleadoID() const;
    void setEmpleadoID(int id);
    int getProductoID() const;
    void setProductoID(int id);
    Modo getModoTransaccion() const;
    void setModoTransaccion(Modo modo);

    void mostrarInfo() override;
};

int Transaccion::getNumFolio() const
{
    return this->numFolio;
}
void Transaccion::setNumFolio(int folio)
{
    this->numFolio = folio;
}
int Transaccion::getClienteID() const
{
    return this->clienteID;
}
void Transaccion::setClienteID(int id)
{
    this->clienteID = id;
}
int Transaccion::getEmpleadoID() const
{
    return this->empleadoID;
}
void Transaccion::setEmpleadoID(int id)
{
    this->empleadoID = id;
}
int Transaccion::getProductoID() const
{
    return this->productoID;
}
void Transaccion::setProductoID(int id)
{
    this->productoID = id;
}
Modo Transaccion::getModoTransaccion() const
{
    return this->modoTransaccion;
}
void Transaccion::setModoTransaccion(Modo modo)
{
    this->modoTransaccion = modo;
}

Transaccion::Transaccion()
{
    this->numFolio = 0;
    this->clienteID = 0;
    this->empleadoID = 0;
    this->productoID = 0;
    this->modoTransaccion = Renta;
}

Transaccion::Transaccion(int numFolio, int clienteID, int empleadoID, int productoID, Modo modoTransaccion)
{
    this->numFolio = numFolio;
    this->clienteID = clienteID;
    this->empleadoID = empleadoID;
    this->productoID = productoID;
    this->modoTransaccion = modoTransaccion;
}

Transaccion::~Transaccion() {}

void Transaccion::mostrarInfo()
{
    cout << fixed << setprecision(2);
    impColor("\n\t========== DETALLE DE TRANSACCION ==========", BLANCO);
    impColor("\n\tFolio:          " + to_string(getNumFolio()), BLANCO);
    impColor("\n\tID Cliente:     " + to_string(getClienteID()), BLANCO);
    impColor("\n\tID Empleado:    " + to_string(getEmpleadoID()), BLANCO);
    impColor("\n\tID Producto:    " + to_string(getProductoID()), BLANCO);
    impColor("\n\tTipo:           " + string(getModoTransaccion() == Renta ? "Renta" : "Venta"), BLANCO);
    impColor("\n\t============================================\n\n", BLANCO);
}