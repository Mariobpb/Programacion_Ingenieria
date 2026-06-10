#pragma once
#include <iostream>
#include <string>

#include "Mostrable.cpp"
#include "UI.cpp"

using namespace std;

enum Estatus
{
    Disponible,
    Rentada,
    Vendida
};

class Producto : public Mostrable
{
protected:
    int ID;
    int numCopia;
    string nombre;
    string genero;
    double precioVenta;
    double precioRenta;
    Estatus estado;

private:
    static int contadorProductos;

public:
    Producto();
    Producto(int numCopia, string nombre, string genero, double precioVenta, double precioRenta);
    virtual ~Producto();

    int getID();
    void setID(int);

    int getNumCopia();
    void setNumCopia(int);

    string getNombre();
    void setNombre(string);

    string getGenero();
    void setGenero(string);

    double getPrecioVenta();
    void setPrecioVenta(double);

    double getPrecioRenta();
    void setPrecioRenta(double);

    Estatus getEstado();
    void setEstado(Estatus);

    string getEstadoString();
    void mostrarInfo() override = 0;
};

int Producto::contadorProductos = 0;

Producto::Producto()
{
    Producto::contadorProductos++;
    this->ID = Producto::contadorProductos;
    this->numCopia = 0;
    this->nombre = "SIN ASIGNAR";
    this->genero = "SIN ASIGNAR";
    this->precioVenta = 0.0;
    this->precioRenta = 0.0;
    this->estado = Disponible;
}

Producto::Producto(int numCopia, string nombre, string genero, double precioVenta, double precioRenta)
{
    Producto::contadorProductos++;
    this->ID = Producto::contadorProductos;
    this->numCopia = numCopia;
    this->nombre = nombre;
    this->genero = genero;
    this->precioVenta = precioVenta;
    this->precioRenta = precioRenta;
    this->estado = Disponible;
}

Producto::~Producto() {}

int Producto::getID()
{
    return this->ID;
}
void Producto::setID(int id)
{
    this->ID = id;
}

int Producto::getNumCopia()
{
    return this->numCopia;
}
void Producto::setNumCopia(int numCopia)
{
    this->numCopia = numCopia;
}

string Producto::getNombre()
{
    return this->nombre;
}
void Producto::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Producto::getGenero()
{
    return this->genero;
}
void Producto::setGenero(string genero)
{
    this->genero = genero;
}

double Producto::getPrecioVenta()
{
    return this->precioVenta;
}
void Producto::setPrecioVenta(double precioVenta)
{
    this->precioVenta = precioVenta;
}

double Producto::getPrecioRenta()
{
    return this->precioRenta;
}
void Producto::setPrecioRenta(double precioRenta)
{
    this->precioRenta = precioRenta;
}

Estatus Producto::getEstado()
{
    return this->estado;
}
void Producto::setEstado(Estatus estado)
{
    this->estado = estado;
}

string Producto::getEstadoString()
{
    switch (this->estado)
    {
    case Disponible:
        return "Disponible";
    case Rentada:
        return "Rentada";
    case Vendida:
        return "Vendida";
    default:
        return "Desconocido";
    }
}