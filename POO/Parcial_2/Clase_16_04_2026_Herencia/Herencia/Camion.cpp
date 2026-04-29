// Definir un camion que hereda de la clase VehiculoRodante
// VehiculoRodante es la clase padre de la clase camion
// En otras palabras VehiculoRodante es la clase base y
// Camion es la clase derivada

using namespace std;

class Camion : public VehiculoRodante {
    private:
        //Atributo de la clase Camion
        int carga;
    public:
        Camion(int, int, int);
        Camion();
        Camion(int);

        void setCarga(int carga) { this->carga = carga; }
        int getCarga() { return carga; }
        void mostrar();

};

Camion::Camion(int carga, int ruedas, int pasajeros) :
                            VehiculoRodante(ruedas, pasajeros){

    this->carga = carga;
}

Camion::Camion(){
    this->carga = 0;
}

Camion::Camion(int carga){
    this->carga = carga;
}

void Camion::mostrar(){
    cout << "Camion" << endl;
    VehiculoRodante::mostrar();
    cout << "Capacidad de carga en pies cubicos: " << getCarga() << endl;
}