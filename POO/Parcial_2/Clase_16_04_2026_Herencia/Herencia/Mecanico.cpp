
using namespace std;

class Mecanico{
    private:
        string nombre;

    public:
        void setNombre(string nombre) { this->nombre = nombre; }
        string getNombre() { return this->nombre; }
        void definirCarga(Camion&);
        void definirPasajeros(Automovil&);
};

void Mecanico::definirCarga(Camion &objC){
    int carga;
    cout << endl << getNombre() << "Ingresa la carga del camion : ";
    cin >> carga;
    objC.setCarga(carga);
}
void Mecanico::definirPasajeros(Automovil &objA){
    int pasajeros;
    cout << endl << getNombre() << "Ingresa los pasajeros del auto : ";
    cin >> pasajeros;
    objA.setPasajeros(pasajeros);
}