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

string Persona::getNombre() {
    return nombre;
}

int Persona::getEdad() {
    return edad;
}

string Persona::getCarrera() {
    return carrera;
}

string Persona::getEstatus() {
    return estatus;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setCarrera(string carrera) {
    this->carrera = carrera;
}

void Persona::setEstatus(string estatus) {
    this->estatus = estatus;
}