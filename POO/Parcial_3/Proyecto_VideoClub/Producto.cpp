#include <iostream>
#include <string>

using namespace std;

enum Estatus
{
    Disponible,
    Rentada,
    Vendida
};

class Producto : public Mostrable
{
private:
    int productoID;
    int numCopia;
    string nombre;
    string genero;
    double precioVenta;
    double precioRenta;
    Estatus estado;

    public:
    Producto();
    Producto(int productoID, int numCopia, string nombre, string genero, double precioVenta, double precioRenta);
    ~Producto();

    int getProductoID();
    void setProductoID(int);

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


    void mostrarInfo() override;
};