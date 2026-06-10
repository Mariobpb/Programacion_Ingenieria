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
    int rentadas; 
    int vendidas; 
    string nombre;
    string genero;
    double precioVenta;
    double precioRenta;
    Estatus estado;

private:
    static int contadorProductos;

public:
    Producto();
    Producto(string nombre, string genero, double precioVenta, double precioRenta);
    virtual ~Producto();

    int getID();
    void setID(int);

    int getNumCopia();
    void setNumCopia(int);

    int getRentadas();
    void setRentadas(int);

    int getVendidas();
    void setVendidas(int);

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
    this->ID = ++Producto::contadorProductos;
    this->numCopia = 0;
    this->nombre = "SIN ASIGNAR";
    this->genero = "SIN ASIGNAR";
    this->precioVenta = 0.0;
    this->precioRenta = 0.0;
    this->estado = Disponible;
    this->rentadas = 0; 
    this->vendidas = 0; 
}

Producto::Producto(string nombre, string genero, double precioVenta, double precioRenta)
{
    this->ID = ++Producto::contadorProductos;
    this->numCopia = 5;
    this->nombre = nombre;
    this->genero = genero;
    this->precioVenta = precioVenta;
    this->precioRenta = precioRenta;
    this->estado = Disponible;
    this->rentadas = 0; 
    this->vendidas = 0; 
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

int Producto::getRentadas()
{
    return this->rentadas;
}
void Producto::setRentadas(int rentadas)
{
    this->rentadas = rentadas;
}

int Producto::getVendidas()
{
    return this->vendidas;
}
void Producto::setVendidas(int vendidas)
{
    this->vendidas = vendidas;
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