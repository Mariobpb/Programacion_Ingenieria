#include <iostream>
#include "Volador.cpp"
#include "Animal.cpp"
using namespace std;


// ========== Clase Murcielago que implementa Volador y Animal ==========
class Murcielago : public Volador, public Animal {
    public:
        void despegar() override {
            cout << "El murcielago despliega sus alas." << endl;
        }
        void aterrizar() override {
            cout << "El murcielago utiliza sus patas." << endl;
        }
        void comer() override {
            cout << "El murcielago come frutas y toma sangre animal." << endl;
        }
        void dormir() override {
            cout << "El murcielago duerme de cabeza." << endl;
        }
};
// ========== Programa principal ==========
int main() {
    Murcielago m;
    m.despegar();
    m.aterrizar();
    m.comer();
    m.dormir();
    return 0;
}