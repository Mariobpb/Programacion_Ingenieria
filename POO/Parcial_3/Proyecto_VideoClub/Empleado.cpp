#include <iostream>
#include <string>

#include "Persona.cpp"

using namespace std;

class Empleado : public Persona {
    private:
        int empleadoID;
        double salario;
        double comision;

};