using namespace std;

class PagoTarjetaCredito : public Pago
{
public:
    void realizarPago(double monto) override;
    string obtenerMetodoPago() override;
};
void PagoTarjetaCredito::realizarPago(double monto){
    if (monto > 0){
        cout << "\nMonto pagado: " << monto << endl;
        cout << "Pago realizado con tarjeta de credito" << endl;
    } else {
        cout << "El monto a pagar es invalido" << endl;
    }
}
string PagoTarjetaCredito::obtenerMetodoPago(){
    return  "\nTarjeta de credito";
}