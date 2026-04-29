using namespace std;

class Persona {
    protected:
        string nombre;
        int edad;
        string carrera;
        string estatus;

    public:
        Persona();
        Persona(string, int, string);
        string getNombre();
        int getEdad();
        string getCarrera();
        string getEstatus();

        void setNombre(string);
        void setEdad(int);
        void setCarrera(string);
        void setEstatus(string);
};

Persona::Persona(){
    this->estatus = "ACTIVO";
}

Persona::Persona(string nombre, int edad, string carrera){
    this->nombre = nombre;
    this->edad = edad;
    this->carrera = carrera;
    this->estatus = "ACTIVO";
}

string Persona::getNombre() { return this->nombre; }
int Persona::getEdad() { return this->edad; }
string Persona::getCarrera() { return this->carrera; }
string Persona::getEstatus() { return this->estatus; }

void Persona::setNombre(string nombre) { this->nombre = nombre; }
void Persona::setEdad(int edad) { this->edad = edad; }
void Persona::setCarrera(string carrera) { this->carrera = carrera; }
void Persona::setEstatus(string estatus) { this->estatus = estatus; }