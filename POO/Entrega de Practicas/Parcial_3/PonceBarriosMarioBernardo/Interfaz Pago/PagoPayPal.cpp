using namespace std;

class PagoPayPal : public Pago
{
public:
    void realizarPago(double monto) override;
    string obtenerMetodoPago() override;
};
void PagoPayPal::realizarPago(double monto){
    if (monto > 0){
        cout << "\nMonto pagado: " << monto << endl;
        cout << "El pago se esta redireccionando a PayPal.com" << endl;
    } else {
        cout << "El monto a pagar es invalido para la plataforma de PayPal" << endl;
    }
}
string PagoPayPal::obtenerMetodoPago(){
    return "\nPayPal";
}