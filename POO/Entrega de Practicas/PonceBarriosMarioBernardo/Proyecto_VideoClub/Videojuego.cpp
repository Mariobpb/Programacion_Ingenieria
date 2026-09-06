#include <iostream>
#include <string>

#include "Producto.cpp"
#include "Mostrable.cpp"

using namespace std;

class Videojuego : public Producto, public Mostrable
{
public:
    Videojuego();
    Videojuego(int productoID, int numCopia, string nombre, string genero, double precioVenta, double precioRenta, string director);
    ~Videojuego();

    void mostrarInfo() override;
};