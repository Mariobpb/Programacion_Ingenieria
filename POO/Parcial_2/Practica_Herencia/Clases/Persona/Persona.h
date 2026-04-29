#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

class Persona {
    protected:
        string nombre;
        int edad;
        string carrera;
        string estatus;

    public:
        string getNombre();
        int getEdad();
        string getCarrera();
        string getEstatus();

        void setNombre(string);
        void setEdad(int);
        void setCarrera(string);
        void setEstatus(string);
};
#endif