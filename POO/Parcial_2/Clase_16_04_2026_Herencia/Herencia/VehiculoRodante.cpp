
using namespace std;

// Definir una clase base (Clase Padre)
class VehiculoRodante {
    //Atributos de la clase VehiculoRodante
    private:
        int ruedas;
        int pasajeros;
    public:

        //Las clases que hereden de VehiculoRodante siempre pueden 
        //constructor de la clase padre

        VehiculoRodante(int ruedas, int pasajeros) {
            this->ruedas = ruedas;
            this->pasajeros = pasajeros;
        }

        VehiculoRodante() {
            this->ruedas = 0;
            this->pasajeros = 0;
        }

        //Métodos getter y setters de la clase
        void setRuedas(int ruedas) { this->ruedas = ruedas; }
        int getRuedas() { return this->ruedas; }
        void setPasajeros(int pasajeros) { this->pasajeros = pasajeros; }
        int getPasajeros() { return this->pasajeros; }

        void mostrar() {
            cout << "Ruedas: " << getRuedas() << endl;
            cout << "Pasajeros: " << getPasajeros() << endl;
        }

};