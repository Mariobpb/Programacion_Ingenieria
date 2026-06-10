using namespace std;

class PagoCriptoMoneda : public Pago
{
public:
    void realizarPago(double monto) override;
    string obtenerMetodoPago() override;
};
void PagoCriptoMoneda::realizarPago(double monto)
{
    if (monto > 0)
    {
        cout << "\nMonto pagado: " << monto << endl;
        cout << "Pago realizado con Criptomoneda\nCobrando 2% de comision del monto... (" << monto * .02 << "$)" << endl;
    }
    else
    {
        cout << "El monto a pagar es invalido para pagar en Criptomoneda" << endl;
    }
}
string PagoCriptoMoneda::obtenerMetodoPago()
{
    return "\nCriptomoneda";
}