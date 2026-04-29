#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "../Persona/Persona.h"
#include "../Alumno/Alumno.h"
#include "../Docente/Docente.h"

using namespace std;

class Director : public Persona {
    public:
        void leer_valores();
        void imprimir_valores();
        void eliminar_alumno(Alumno);
        void eliminar_docente(Docente);
};
#endif