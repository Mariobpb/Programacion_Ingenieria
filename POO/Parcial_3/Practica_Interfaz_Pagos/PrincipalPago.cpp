#include <iostream>
#include <string>
#include <vector>
// Incluir las clases que implementan la interfaz
#include "Pago.cpp"
#include "PagoTarjetaCredito.cpp"
#include "PagoPayPal.cpp"
#include "PagoCriptoMoneda.cpp"

using namespace std;

int main()
{
    // Vector de punteros a Pago
    vector<Pago *> metodosPago = {
        new PagoTarjetaCredito(),
        new PagoPayPal(),
        new PagoCriptoMoneda()};
    double monto = 100.00;
    for (Pago *metodo : metodosPago)
    {
        cout << "Metodo: " << metodo->obtenerMetodoPago() << endl;
        metodo->realizarPago(monto);
        cout << "-----------------------------" << endl;
    }
    // Liberar memoria
    for (Pago *metodo : metodosPago)
    {
        delete metodo;
    }
    return 0;
}