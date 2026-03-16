#include <iostream>
using namespace std;

class Persona
{
    // Atributos de la clase
private:
    string nombre;
    int edad;

    // Métodos de la clase
public:
    // constructores de la clase
    Persona();
    Persona(string nombre);
    Persona(string nombre, int edad);
    ~Persona();

    void setNombre(string nombre);
    string getNombre();
    void setEdad(int edad);
    int getEdad();

    void mostrarDatos();
};
Persona::~Persona(){
    cout << "Soy " << getNombre() << " y falleci" << endl;
}
Persona::Persona()
{
    nombre = "";
    edad = 0;
}
Persona::Persona(string nombre)
{
    this->nombre = nombre;
    edad = 10;
}
Persona::Persona(string nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}

void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}
string Persona::getNombre()
{
    return this->nombre;
}
void Persona::setEdad(int edad)
{
    this->edad = edad;
}
int Persona::getEdad()
{
    return this->edad;
}
void Persona::mostrarDatos()
{
    cout << "Soy : " << getNombre() << " tengo " << getEdad() << " anios" << endl;
}

int main()
{
    Persona objeto1;
    Persona objeto2("Mario Ponce", 21);
    Persona objeto3("Julian");

    Persona* objeto4 = new Persona("Susana", 25);

    
    objeto1.mostrarDatos();
    objeto2.mostrarDatos();
    objeto3.mostrarDatos();
    objeto4->mostrarDatos();

    delete objeto4;
    
    return 0;
}