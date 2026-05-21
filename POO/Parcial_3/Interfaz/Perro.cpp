#include <iostream>
#include "Animal.cpp"

// Clase Perro que implementa la interfaz Animal
class Perro : public Animal {
    public:
    void comer() override {
        cout << "El perro come croquetas." << endl;
    }
    void dormir() override {
        cout << "El perro duerme acostado en el suelo." << endl;
    }
};
// Programa principal
int main() {
    Perro perro;
    perro.comer();
    perro.dormir();
    return 0;
}