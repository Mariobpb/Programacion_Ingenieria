#include "Escuela.h"
#include <iostream>

using namespace std;

void Escuela::menu_principal()
{
    int opcion;
    do
    {
        cout << "==================================================================";
        cout << "\n\n\tMenu Principal:" << endl;
        cout << "\t\t1. Alumno" << endl;
        cout << "\t\t2. Docente" << endl;
        cout << "\t\t3. Director" << endl;
        cout << "\t\t4. Salir del sistema\n\n" << endl;
        cout << "==================================================================";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            menu_alumno();
            break;
        case 2:
            menu_docente();
            break;
        case 3:
            menu_director();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);
}

void Escuela::menu_alumno()
{
    
}

void Escuela::menu_docente()
{
    
}

void Escuela::menu_director()
{
    
}