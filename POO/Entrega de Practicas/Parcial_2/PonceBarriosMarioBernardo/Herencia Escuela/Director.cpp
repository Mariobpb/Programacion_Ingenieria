using namespace std;

class Director : public Persona {
    public:
        void leer_valores();
        void imprimir_valores();
        void eliminar_alumno(Alumno&);
        void eliminar_docente(Docente&);
};

void Director::leer_valores() {
    string nombre, carrera;
    int edad;

    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese la carrera: ";
    cin >> carrera;

    setNombre(nombre);
    setEdad(edad);
    setCarrera(carrera);
}

void Director::imprimir_valores() {
    cout << "################# VALORES DEL DIRECTOR #################\n" << endl;
    cout << "\tNombre: | " << getNombre() << " |" << endl;
    cout << "\tEdad: | " << getEdad() << " |" << endl;
    cout << "\tCarrera: | " << getCarrera() << " |" << endl;
    cout << "\n################# VALORES DEL DIRECTOR #################" << endl;
}

void Director::eliminar_alumno(Alumno &alumno) {
    cout << alumno.getNombre() << " ha sido dado de baja por " << getNombre() << endl;
    alumno.cambiar_estatus("BAJA");
}

void Director::eliminar_docente(Docente &docente) {
    cout << docente.getNombre() << " ha sido dado de baja por " << getNombre() << endl;
    docente.cambiar_estatus("BAJA");
}