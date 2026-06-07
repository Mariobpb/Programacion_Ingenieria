#include <iostream>
#include <string>

using namespace std;

enum status
{
    Disponible,
    Rentada,
    Vendida
};

class Producto
{
private:
    int numCopias;
    string nombre;
    string genero;
    double precioVenta;
    double precioRenta;
    status estado;
};