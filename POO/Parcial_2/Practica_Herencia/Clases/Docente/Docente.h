#ifndef DOCENTE_H
#define DOCENTE_H

#include "../Persona/Persona.h"

using namespace std;

class Docente : public Persona {
    private:
        int numNomina;
        float salario;
        float horasTrab;

    public:
        void leer_valores();
        void imprimir_valores();
        void calcular_salario();
        float obtener_salario();
        void cambiar_estatus();
};
#endif