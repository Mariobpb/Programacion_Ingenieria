#include <iostream>
#include <string>

#include "Mostrable.cpp"

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

    int getNumFolio();
    void getNumFolio(int);

    int getClienteID();
    void getClienteID(int);

    int getEmpleadoID();
    void getEmpleadoID(int);

    int getProductoID();
    void getProductoID(int);

    Modo getModoTransaccion();
    void getModoTransaccion(Modo);

    void mostrarInfo() override;
};