#include <iostream>
#include "Volador.cpp"

using namespace std;
// Clase Aguila que implementa la interfaz Volador
class Aguila : public Volador {
    public:
        void despegar() override {
            cout << "El aguila despliega sus alas." << endl;
        }
        void aterrizar() override {
            cout << "El aguila utiliza sus patas y alas para ." << endl;
        }
};

// Ejemplo de uso
int main() {
    Aguila aguila;
    aguila.despegar();
    aguila.aterrizar();
    return 0;
}