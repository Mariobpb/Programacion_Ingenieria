using namespace std;

class Director : public Persona {
    public:
        void leer_valores();
        void imprimir_valores();
        void eliminar_alumno(Alumno);
        void eliminar_docente(Docente);
};

void Director::leer_valores() {
    
}

void Director::imprimir_valores() {
    
}

void Director::eliminar_alumno(Alumno alumno) {
    
}

void Director::eliminar_docente(Docente docente) {
    cout << "Eliminando docente: " << docente.getNombre() << endl;
    // Lógica para eliminar
}