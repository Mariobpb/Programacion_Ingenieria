#include <iostream>
#include <string>

#include "Producto.cpp"

using namespace std;

class Pelicula : public Producto
{
private:
    int peliculaID;
    string director;
};