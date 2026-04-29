#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include "../Persona/Persona.h"

using namespace std;

class Alumno : public Persona {
    private:
        string registro;
        float promedio;
        float calMat;
        float calProgra;
        float calAlgebra;

    public:
        void leerValores();
        void calcular_promedio();
        void cambiar_estatus(string);
        void imprimir_valores();
        void obtener_promedio();
};
#endif