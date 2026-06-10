#pragma once
#include <iostream>
#include <string>

#include "Producto.cpp"

using namespace std;

class Videojuego : public Producto
{
public:
    Videojuego();
    Videojuego(int numCopia, string nombre, string genero, double precioVenta, double precioRenta);
    ~Videojuego();

    void mostrarInfo() override;
};

Videojuego::Videojuego() : Producto()
{
}

Videojuego::Videojuego(int numCopia, string nombre, string genero, double precioVenta, double precioRenta)
    : Producto(numCopia, nombre, genero, precioVenta, precioRenta)
{
}

Videojuego::~Videojuego()
{
}

void Videojuego::mostrarInfo()
{
    impColor("\n\tID del producto (Videojuego): " + to_string(getID()), VERDE);
    impColor("\n\tNombre:                  " + getNombre(), VERDE);
    impColor("\n\tGenero:                  " + getGenero(), VERDE);
    impColor("\n\tNumero de Copias:        " + to_string(getNumCopia()), VERDE);
    impColor("\n\tPrecio Venta:            $" + to_string(getPrecioVenta()), VERDE);
    impColor("\n\tPrecio Renta:            $" + to_string(getPrecioRenta()), VERDE);
    impColor("\n\tEstatus Actual:          " + getEstadoString(), VERDE);
}