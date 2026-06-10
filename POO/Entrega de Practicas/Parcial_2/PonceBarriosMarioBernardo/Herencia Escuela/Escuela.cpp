using namespace std;

class Escuela
{
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
        cout << "\nOpcion: " << endl;
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
    string registro;
    int opcion;
    do
    {
        cout << "------------------------------------------------------------------";
        cout << "\n\n\tMenu Alumno:" << endl;
        cout << "\t\t1. Capturar datos del alumno" << endl;
        cout << "\t\t2. Calcular promedio" << endl;
        cout << "\t\t3. Mostrar datos del alumno" << endl;
        cout << "\t\t4. Regresar al menu principal\n\n" << endl;
        cout << "------------------------------------------------------------------";
        cout << "\nOpcion: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            objAlumno.leerValores();
            break;
        case 2:
            cout << "Ingrese el registro del alumno a calcular su promedio: ";
            cin >> registro;
            if (objAlumno.getRegistro() == registro)
                objAlumno.calcular_promedio();
            else
                cout << "Registro invalido" << endl;
            break;
        case 3:
            objAlumno.imprimir_valores();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);
}

void Escuela::menu_docente()
{
    int numNomina;
    int opcion;
    do
    {
        cout << "------------------------------------------------------------------";
        cout << "\n\n\tMenu Docentes:" << endl;
        cout << "\t\t1. Capturar datos del docente" << endl;
        cout << "\t\t2. Calcular salario" << endl;
        cout << "\t\t3. Mostrar datos del docente" << endl;
        cout << "\t\t4. Regresar al menu principal\n\n" << endl;
        cout << "------------------------------------------------------------------";
        cout << "\nOpcion: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            objDocente.leer_valores();
            break;
        case 2:
            cout << "Ingrese el numero de nomina del docente a calcular su salario: ";
            cin >> numNomina;
            if (objDocente.getNumNomina() == numNomina)
                objDocente.calcular_salario();
            else
                cout << "Numero de nomina invalido" << endl;
            break;
        case 3:
            objDocente.imprimir_valores();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);
}

void Escuela::menu_director()
{
    string registro;
    int numNomina;
    int opcion;
    do
    {
        cout << "------------------------------------------------------------------";
        cout << "\n\n\tMenu Director:" << endl;
        cout << "\t\t1. Capturar datos del director" << endl;
        cout << "\t\t2. Mostrar datos del director" << endl;
        cout << "\t\t3. Dar de baja al alumno" << endl;
        cout << "\t\t4. Dar de baja al docente" << endl;
        cout << "\t\t5. Regresar al menu principal\n\n" << endl;
        cout << "------------------------------------------------------------------";
        cout << "\nOpcion: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            objDirector.leer_valores();
            break;
        case 2:
            objDirector.imprimir_valores();
            break;
        case 3:
            cout << "Ingrese el registro del alumno a dar de baja: ";
            cin >> registro;
            if (objAlumno.getRegistro() == registro)
                objDirector.eliminar_alumno(objAlumno);
            else
                cout << "Registro invalido" << endl;
            break;
        case 4:
            cout << "Ingrese el numero de nomina del docente a dar de baja: ";
            cin >> numNomina;
            if (objDocente.getNumNomina() == numNomina)
                objDirector.eliminar_docente(objDocente);
            else
                cout << "Numero de nomina invalido" << endl;
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    } while (opcion != 5);
}