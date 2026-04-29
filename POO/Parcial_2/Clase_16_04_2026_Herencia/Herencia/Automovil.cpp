using namespace std;

//Se define una enumeración
enum tipo{carro, van, camioneta};

//Definir un automovil que también hereda de la clase VehiculoRodante
class Automovil : public VehiculoRodante {

    //El atributo de la clase es de la enumeración creada
    private:
        enum tipo tipoCarro;

    public:
        void setTipoCarro(tipo tipoCarro) { this->tipoCarro = tipoCarro; }
        enum tipo getTipoCarro() { return tipoCarro; };
        void mostrar();
        Automovil();

};


Automovil::Automovil() : VehiculoRodante() {

}

void Automovil::mostrar() {
    cout << "Automovil" << endl;
    VehiculoRodante::mostrar();
    switch (getTipoCarro()) {
    case van:
        cout << "El tipo de automovil es : van" << endl;
        break;
    case carro:
        cout << "El tipo de automovil es : carro" << endl;
        break;
    case camioneta:
        cout << "El tipo de automovil es : camioneta" << endl;
        break;
    
    default:
        break;
    }
}