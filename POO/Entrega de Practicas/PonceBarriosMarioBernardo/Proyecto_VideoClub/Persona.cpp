#include <iostream>
#include <string>

#include "Mostrable.cpp"

using namespace std;

class Persona : public Mostrable
{
private:
    string nombre;
    string domicilio;
    int telefono;
    string RFC;

public:
    Persona();
    Persona(string nombre, string domicilio, int telefono, string RFC);
    ~Persona();

    string getNombre();
    void setNombre(string);

    string getDomicilio();
    void setDomicilio(string);

    int getTelefono();
    void setTelefono(int);

    string getRFC();
    void setRFC(string);

    void mostrarInfo() override;

};