#include <iostream>
#include <string>

#include "Producto.cpp"
#include "Mostrable.cpp"

using namespace std;

class Pelicula : public Producto, public Mostrable
{
private:
    string director;

    public:
    Pelicula();
    Pelicula(int productoID, int numCopia, string nombre, string genero, double precioVenta, double precioRenta, string director);
    ~Pelicula();


    void mostrarInfo() override;
};