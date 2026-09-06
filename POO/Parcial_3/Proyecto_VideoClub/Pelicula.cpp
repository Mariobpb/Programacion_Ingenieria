#include <iomanip>
#pragma once
#include <iostream>
#include <string>

#include "Producto.cpp"

using namespace std;

class Pelicula : public Producto
{
private:
    string director;

public:
    Pelicula();
    Pelicula(string nombre, string genero, double precioVenta, double precioRenta, string director);
    ~Pelicula();

    string getDirector();
    void setDirector(string);

    void mostrarInfo() override;
};

Pelicula::Pelicula() : Producto()
{
    this->director = "SIN ASIGNAR";
}

Pelicula::Pelicula(string nombre, string genero, double precioVenta, double precioRenta, string director)
    : Producto(nombre, genero, precioVenta, precioRenta)
{
    this->director = director;
}

Pelicula::~Pelicula()
{
}

string Pelicula::getDirector()
{
    return this->director;
}
void Pelicula::setDirector(string director)
{
    this->director = director;
}

void Pelicula::mostrarInfo()
{
    cout << fixed << setprecision(2);
    impColor("\n\tID del producto (Pelicula):   " + to_string(ID), VERDE);
    impColor("\n\tNombre:                       " + nombre, VERDE);
    impColor("\n\tDirector:                     " + director, VERDE);
    impColor("\n\tGenero:                       " + genero, VERDE);
    impColor("\n\tNumero de Copias:             " + to_string(numCopia), VERDE);
    impColor("\n\tPrecio Venta:                 $" + to_string(precioVenta), VERDE);
    impColor("\n\tPrecio Renta:                 $" + to_string(precioRenta), VERDE);
    impColor("\n\tEstatus Actual:               " + getEstadoString(), VERDE);
}