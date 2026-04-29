#ifndef ESCUELA_H
#define ESCUELA_H

#include "../Alumno/Alumno.h"
#include "../Docente/Docente.h"
#include "../Director/Director.h"

using namespace std;

class Escuela{
    private:
        Alumno objAlumno;
        Docente objDocente;
        Director objDirector;

    public:
        void menu_alumno();
        void menu_docente();
        void menu_director();
        void menu_principal();
};
#endif