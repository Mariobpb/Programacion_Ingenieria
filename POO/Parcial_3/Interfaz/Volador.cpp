using namespace std;

// Interfaz en C++ (clase abstracta pura)
class Volador {
    public:
        virtual void despegar() = 0; // método puramente virtual
        virtual void aterrizar() = 0; // método puramente virtual
};